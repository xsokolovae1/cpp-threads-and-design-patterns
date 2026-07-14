#include <iostream>
#include <string>
using namespace std;


class IState {
public:
    virtual void call(const string& number) = 0;
    virtual void receiveCall() = 0;
};

class NormalState : public IState {
public:
    void call(const string& number) override {
        cout << "Calling " << number << "\n";
    }
    void receiveCall() override {
        cout << "Ring ring!\n";
    }
};

class SilentState : public IState {
public:
    void call(const string& number) override {
        cout<<"calling"<< number << endl;
    }
    void receiveCall() override {
        cout <<" recievnig" ;
    }
};

class OffState : public IState {
public:
    void call(const string& number) override {
        cout << " OFF";
    }
    void receiveCall() override {
        cout << "OFF";
    }
};

class Phone {
private:
    IState* state;
public:
    Phone() { state = new NormalState(); }
    void setState(IState* s) { 
        state = s; }
    void call(const string& number) { 
        state->call(number); }
    void receiveCall() { 
        state->receiveCall(); }
};

int main() {
    Phone phone;
    phone.setState(new OffState());
    phone.call("4324032");
    phone.receiveCall();
}