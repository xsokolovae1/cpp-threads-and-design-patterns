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
#include<string>
#include<atomic>
#include<map>

std:: queue<char> sharedQueue;
std:: map<char,int> myMap;
std:: mutex mtx;
std::atomic<bool> done = false;
std::condition_variable cv;

void producer(){

    std::ifstream file("input.txt");
    char ch;
    while(file.get(ch)){
        if(std::isalpha(ch)){
            std::lock_guard<std::mutex> lock(mtx);
            sharedQueue.push(ch);
            cv.notify_one();
        }

        done = true;
        cv.notify_all();
    }
}

void consumer(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return done.load();});
    while(!sharedQueue.empty()){
        char ch = std::tolower(sharedQueue.front());
        sharedQueue.pop();
        
        myMap[ch]++;
    }

}

int main(){

    std::thread t1(producer);
    std::thread t2(consumer);


    t1.join();
    t2.join();

    for(auto& pair : myMap)
        std::cout<<pair.first << " : " << pair.second << std::endl;

    auto min = std:: min_element(myMap.begin(), myMap.end(), [](const auto& a, const auto& b){return a.second < b.second;});
    std::cout << "Min" << min->first << min->second << std::endl;

    auto max = std:: max_element(myMap.begin(), myMap.end(), [](const auto& a, const auto& b){return a.second < b.second;});
    std::cout << "Max" << max->first << max->second << std::endl;


}