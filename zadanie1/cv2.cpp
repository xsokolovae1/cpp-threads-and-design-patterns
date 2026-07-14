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

std::queue<char> sharedQueque;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

std::vector<int> container1;
std::vector<int> container2;

void producer(){
    std::ifstream file("input.txt");
    char ch;
    while(file.get(ch)){
        std::lock_guard<std::mutex> lock(mtx);
        if(std::isdigit(ch)){
            sharedQueque.push(ch);
            cv.notify_one();
        }
    }

    std::lock_guard<std::mutex> lock(mtx);
    done = true;
    cv.notify_all();
        

}

void consumer(){

    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{return !sharedQueque.empty()||done;});

    while(!sharedQueque.empty()){
        char ch = sharedQueque.front();
        sharedQueque.pop();
        int num = ch - '0';
        container1.push_back(num);
        container2.push_back(num);

    }
}

int main(){ 

    std::thread producerThread(producer);
    std::thread consumerThread(consumer);


    producerThread.join();
    consumerThread.join();
    
    std::sort(container1.begin(), container1.end(), std::greater<int>());    
    std::sort(container2.begin(), container2.end());



    std::cout << "Container1";
    for(int num : container1) std::cout<<num;
    std::cout << std::endl;



    std::cout << "Container2";
    for(int num : container2) std::cout<<num;
    std::cout << std::endl;

    int sum1 = std::accumulate(container1.begin(), container1.end(), 0); //начальное значение сумы 
    int sum2 = std::accumulate(container2.begin(), container2.end(), 0);
    std::cout << "Sum1: " << sum1 << std::endl;
    std::cout << "Sum2: " << sum2 << std::endl;

    return 0;
}