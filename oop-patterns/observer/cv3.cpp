#include <iostream>
#include <string>
#include <vector>
using namespace std;


class IObserver {
    public:
    virtual void update(float temp, float hum)=0;
};


class WeatherStation {
    private:
        vector<IObserver*> observers; 
public:
    float temperature;
    float humidity;

    void sub(IObserver* o){
        observers.push_back(o);
    }

    void notify(float temp, float hum){
        for( auto o: observers)
            o->update(temp, hum);
        
    }

    void setWeather(float temp, float hum) {
        temperature = temp;
        humidity = hum;
        notify(temp, hum);
    }
};

class PhoneDisplay : public IObserver {
public:
    void update(float temp, float hum) override {
        cout << "Phone: " << temp << "C, " << hum << "%\n";
    }
};


class TVDisplay : public IObserver {
public:
    void update(float temp, float hum) override {
        cout << "TV: " << temp << "C, " << hum << "%\n";
    }
};

int main() {
    WeatherStation station;
    PhoneDisplay phone;
    TVDisplay tv;

    station.sub(&phone);
    station.sub(&tv);
    station.setWeather(25.0, 60.0);  // ← добавь!
}