#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <atomic>


std::queue<std::string> sharedQueue;
std::map<std::string, int> myMap;
std::mutex mtx;
std::condition_variable cv;
std::atomic<bool> done = false;
void producer(){

    std::ifstream file("input.txt");
    std:: string word;
    
    while(file >> word){
        std::lock_guard<std::mutex> lock(mtx);
        sharedQueue.push(word); 
        cv.notify_one();
    }
    done = true;
    cv.notify_all();

}

void consumer(){

    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return done.load();});

    while(!sharedQueue.empty()){
        std::string w = sharedQueue.front();
        sharedQueue.pop();

        if(w.size() >=3){
           myMap[w]++; 

        }


    }
}
int main(){

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
 
    
    for(auto& pair: myMap)
         std::cout << pair.first << ": " << pair.second << std::endl;

    auto max = std::max_element(myMap.begin(), myMap.end(), [](const auto& a, const auto& b){return a.second < b.second;});
    std::cout << "Чаще всего: " << max->first << ": " << max->second << std::endl;
}