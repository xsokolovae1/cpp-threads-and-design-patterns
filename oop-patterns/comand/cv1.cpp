#include <iostream>
#include <string>
using namespace std;


class Light {
public:
    void turnOn() { cout << "Light on\n"; }
    void turnOff() { cout << "Light off\n"; }
};

class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TurnOnCommand : public ICommand {
private:
    Light& light;
public:
    TurnOnCommand(Light& l) : light(l) {}
    void execute() override { light.turnOn(); }
    void undo() override { light.turnOff(); }
};

class TurnOffCommand : public ICommand {
private:
    Light& light;
public:
    TurnOffCommand(Light& l) : light(l) {}
    void execute() override { light.turnOff(); }
    void undo() override { light.turnOn(); }
};

// ── INVOKER (тот кто вызывает команду) ──
class RemoteControl {
private:
    ICommand* command;
public:
    void setCommand(ICommand* c) {
        command = c;
    }
    void pressButton() {
        command->execute();
    }
    void pressUndo() {
        command->undo();
    }
};

int main() {
    Light light;
    TurnOnCommand turnOn(light);
    TurnOffCommand turnOff(light);

    RemoteControl remote;
    remote.setCommand(&turnOn);
    remote.pressButton();   // Light on
    remote.pressUndo();     // Light off

    remote.setCommand(&turnOff);
    remote.pressButton();   // Light off
    remote.pressUndo();     // Light on
}
