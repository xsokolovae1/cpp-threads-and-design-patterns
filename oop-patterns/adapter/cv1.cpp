#include <iostream>
#include <string>
using namespace std;


class EuropeanSocket {
public:
    void plugIn220V() {
        cout << "European socket: 220V connected\n";
    }
};


class IAmericanSocket {
public:
    virtual void plugIn110V() = 0;
};


class SocketAdapter : public IAmericanSocket {
private:
    EuropeanSocket european; 
public:
    void plugIn110V() override {
        cout << "Adapter: converting 110V to 220V\n";
        european.plugIn220V();  
    }
};

int main() {
    SocketAdapter adapter;
    adapter.plugIn110V();
}
