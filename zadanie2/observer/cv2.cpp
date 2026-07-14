#include <iostream>
#include <string>
#include <vector>
using namespace std;


class IObserver {
    public:
    virtual void update(float balance) = 0;
};

class Bank {

private:
    vector<IObserver*> obs;
public:
    float balance;
    Bank(float initial) {
        balance = initial;
    }

    void sub(IObserver* o){
        obs.push_back(o);
    }

    void notify(float balance){
        for ( auto o : obs)
            o->update(balance);
        
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", Balance: " << balance << "\n";
        notify(amount);
    }

    void withdraw(float amount) {
        balance -= amount;
        cout << "With   drawn: " << amount << ", Balance: " << balance << "\n";
        notify(balance);
    }
};

class EmailNotification : public IObserver {
public:
    void update(float balance) override {
        cout << "Email: your balance is " << balance << "\n";
    }
};

class SMSNotification : public IObserver{
public:
    void update(float balance) override {
        cout << "SMS: your balance is " << balance << "\n";
    }
};

int main() {
    Bank bank(1000.0);
    EmailNotification email;
    SMSNotification sms;

    bank.sub(&email);
    bank.sub(&sms);

    bank.deposit(1000);
    bank.withdraw(100);

}