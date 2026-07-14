#include <iostream>
#include <string>
using namespace std;

class Computer {
public:
    string cpu;
    string ram;
    string gpu;

    void show() {
        cout << "CPU: " << cpu << "\n";
        cout << "RAM: " << ram << "\n";
        cout << "GPU: " << gpu << "\n";
    }
};


class ComputerBuilder {
private:
    Computer computer;
public:
    ComputerBuilder& setCPU(const string& cpu) {
        computer.cpu = cpu;
        return *this;  
    ComputerBuilder& setRAM(const string& ram) {
        computer.ram = ram;
        return *this;
    }
    ComputerBuilder& setGPU(const string& gpu) {
        computer.gpu = gpu;
        return *this;
    }
    Computer build() {
        return computer;  
    }
};

int main() {
    Computer pc = ComputerBuilder()
        .setCPU("Intel i9")
        .setRAM("32GB")
        .setGPU("RTX 4090")
        .build();

    pc.show();
}
