#include <iostream>
#include <string>
using namespace std;

class TrafficLight;  // forward declaration


class IState {
public:
    virtual void handle(TrafficLight& light) = 0;
};

class RedState : public IState {
public:
    void handle(TrafficLight& light) override;
};

class GreenState : public IState {
public:
    void handle(TrafficLight& light) override;
};

class YellowState : public IState {
public:
    void handle(TrafficLight& light) override;
};


class TrafficLight {
private:
    IState* state;
public:
    TrafficLight() {
        state = new RedState(); 
    }
    void setState(IState* s) {
        state = s;
    }
    void change() {
        state->handle(*this);
    }
};


void RedState::handle(TrafficLight& light) {
    cout << "Red — stop!\n";
    light.setState(new GreenState());
}

void GreenState::handle(TrafficLight& light) {
    cout << "Green — go!\n";
    light.setState(new YellowState());
}

void YellowState::handle(TrafficLight& light) {
    cout << "Yellow — ready!\n";
    light.setState(new RedState());
}

int main() {
    TrafficLight light;
    light.change();  // Red — stop!
    light.change();  // Green — go!
    light.change();  // Yellow — ready!
    light.change();  // Red — stop!
}
