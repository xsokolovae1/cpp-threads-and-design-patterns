#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>

std::queue<char> sharedQueue;
std::mutex mtx;
std::condition_variable cv;
std::vector<char> container1;  // lowercase → uppercased
std::vector<char> container2;  // uppercase → as-is
bool done = false;

void producer() {
    std::ifstream file("input.txt");
    char ch;
    while (file.get(ch)) {
        std::lock_guard<std::mutex> lock(mtx);
        sharedQueue.push(ch);
        cv.notify_one();
    }
    std::lock_guard<std::mutex> lock(mtx);
    done = true;
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !sharedQueue.empty() || done; });

        while (!sharedQueue.empty()) {
            char ch = sharedQueue.front();
            sharedQueue.pop();

            if (std::islower(ch))
                container1.push_back(std::toupper(ch));  // lowercase → uppercase → container1
            else if (std::isupper(ch))
                container2.push_back(ch);                // uppercase → container2
            // digits and others: ignored
        }

        if (done) break;  // exit outer loop only when queue is empty AND producer finished
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();

    std::sort(container2.begin(), container2.end());

    std::cout << "Container1: ";
    for (char c : container1) std::cout << c;
    std::cout << std::endl;

    std::cout << "Container2: ";
    for (char c : container2) std::cout << c;
    std::cout << std::endl;

    return 0;
}