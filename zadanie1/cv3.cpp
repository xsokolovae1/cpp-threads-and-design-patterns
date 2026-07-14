#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>

std::queue<std::string> words;
std::vector<std::string> container1;
std::vector<std::string> container2;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer(){
    std::ifstream file("input.txt");
    std::string word;
    while(file >> word){
        std::lock_guard<std::mutex> lock(mtx);
        words.push(word);
        cv.notify_one();
    }
    std::lock_guard<std::mutex> lock(mtx);
    done = true;
    cv.notify_all();
}

void consumer(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return done;});
    while(!words.empty()){
        std::string w = words.front();
        words.pop();
        if(!std::isalpha(w[0])) continue;  // сначала отсеиваем не-буквы
        char first = std::tolower(w[0]);
        if(first=='a' || first=='e' || first=='i' || first=='o' || first=='u')
            container1.push_back(w);
        else
            container2.push_back(w);
    }
}  // ← эта скобка была потеряна

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();

    std::sort(container1.begin(), container1.end(), [](const std::string& a, const std::string& b){
        return a.size() > b.size();
    });
    std::cout << "Container1: ";
    for(std::string c : container1) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "Size: " << container1.size() << std::endl;

    std::sort(container2.begin(), container2.end());
    std::cout << "Container2: ";
    for(std::string c : container2) std::cout << c << " ";
    std::cout << std::endl;
    std::cout << "Size: " << container2.size() << std::endl;

    return 0;
}