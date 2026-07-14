#include <iostream>
#include <string>
using namespace std;

class OldTemperatureSensor {
public:
    float readFahrenheit() {
        return 98.6;
    }
};

class OldDistanceSensor {
public:
    float readInches() {
        return 12.0;
    }
};

class ITemp{
    public:
    virtual float changing_temp() = 0;
};

class CelsAdapater : public ITemp {
    
    private:

    OldTemperatureSensor oldtemp;
    public:
    float changing_temp()override{

        
        return (oldtemp.readFahrenheit()  - 32) * 5/9;
       
    }
};

class IDist{
    public:

    virtual float changing_dist() = 0;
    }
;

class DistAdapter: public IDist {
    private:
    
    OldDistanceSensor oldsensor;
    public:
    float changing_dist() override{
        return oldsensor.readInches() * 2.54;
    }
};

class SmartDevice {
public:
    void showTemperature(ITemp* temp) {
      cout<<  temp->changing_temp();
       
    }

    void showDistance(IDist* dist) {
       cout<< dist->changing_dist();

       
    }
};

int main() {
    SmartDevice device;
    DistAdapter dist;
    CelsAdapater temp;

    device.showTemperature(&temp);
    device.showDistance(&dist);
   
}