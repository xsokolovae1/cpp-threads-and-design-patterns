#include <iostream>
#include <string>
using namespace std;


class ICommand{
    public:
        virtual void execute() = 0;
        virtual void undo () = 0;
};

class AirConditioner {
public:
    void turnOn() { cout << "AC on\n"; }
    void turnOff() { cout << "AC off\n"; }
};


class Fan {
public:
    void speedUp() { cout << "Fan speed up\n"; }
    void speedDown() { cout << "Fan speed down\n"; }
};

class On : public ICommand{
    private: 

    AirConditioner& ac;

    public:

    On(AirConditioner& a):ac(a){

    }

    void execute() override {
         ac.turnOn();
    }

    void undo() override {
        ac.turnOff();
    }
};

class Off : public ICommand {
    private: 
    AirConditioner& ac;

    public:
    Off(AirConditioner& a) : ac(a){
        
    }
    void execute() override {
        ac.turnOff();
    }
    void undo() override{
        ac.turnOn();
    }
};



class AirCondControl{
private:
    ICommand* command;
public:
    void setCommand(ICommand* c){
        command = c;
    }

    void pressB(){
        command ->execute();
    }
    void pressU(){
        command->undo();
    }

};


class Up : public ICommand {

    private:
    Fan* fan;
    public:
    Up(Fan* f){
        fan = f;
    }

    void execute() override {
        fan->speedUp();
    }
    void undo() override{
        fan->speedDown();
    }
};

class Down: public ICommand{
    private: 
    Fan* fan;
    public:
    Down(Fan* f){
        fan = f;
    
    }
    void execute() override{
        fan->speedDown();
    }
    void undo() override{
        fan->speedUp();
    }     

};

class FanControl{
    private:
    ICommand* command;
    public:

    void setCommand(ICommand* c){
        command = c;
    }
    void pressUp(){
        command->execute();
    }
    void pressDown(){
        command->undo();
    }
};



int main() {
    Fan fan;
    AirConditioner ac;
    Off off(ac);
    On on(ac);
    
    AirCondControl acont;
    acont.setCommand(&off);
    acont.pressB();
    acont.pressU();


    FanControl fcont;
    Up up(&fan);
    Down down(&fan);

    fcont.setCommand(&up);
    fcont.pressUp();
    fcont.pressDown();

}