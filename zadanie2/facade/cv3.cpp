#include <iostream>
#include <string>
using namespace std;

class Engine {
public:
    void start() { cout << "Engine started\n"; }
    void stop() { cout << "Engine stopped\n"; }
};

class GPS {
public:
    void enable() { cout << "GPS enabled\n"; }
    void setDestination(const string& dest) { cout << "GPS destination: " << dest << "\n"; }
    void disable() { cout << "GPS disabled\n"; }
};

class AirConditioning {
public:
    void turnOn() { cout << "AC on\n"; }
    void setTemp(int temp) { cout << "AC temp: " << temp << "\n"; }
    void turnOff() { cout << "AC off\n"; }
};

class Radio {
public:
    void turnOn() { cout << "Radio on\n"; }
    void setStation(const string& station) { cout << "Radio station: " << station << "\n"; }
    void turnOff() { cout << "Radio off\n"; }
};

class Facade{
    Engine engine;
    GPS gps;
    AirConditioning ac;
    Radio radio;

    public:
    void startTrip(const string& destination) {
        engine.start();
        gps.enable();
         gps.setDestination(destination);  // ← используй параметр!
      ac.turnOn();
      ac.setTemp(22);
     radio.turnOn();
         radio.setStation("Europa 2");
    }
    void endTrip() {
        radio.turnOff();
        ac.turnOff();
        gps.disable();
        engine.stop();
}
};

int main() {
   Facade f;
   f.startTrip("albania");
   f.endTrip();

}