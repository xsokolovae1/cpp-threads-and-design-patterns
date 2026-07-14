#include <iostream>
#include <string>
using namespace std; 

class Logger {
private:
    Logger(){}
    static Logger* instance;
        
public:
    static Logger* getInstance(){
        if(instance == nullptr){
            instance = new Logger();
        }

        return instance;
    }
    void display() {
        cout << "Singleton instance." << endl;
    }
    
};

Logger* Logger::instance = nullptr;

class Vehicle {

    public:
    virtual void type() = 0;
    virtual ~Vehicle(){};
};

class Car : public Vehicle {
    public:
        void type(){
            cout << "Driving a car\n";
        }
};
class Bike : public Vehicle {
    public:
        void type(){
            cout << "Riding a bike\n";
        }
};

class Truck: public Vehicle {
    public:
        void type(){
            cout << "Driving a truck\n";
        }
};

class VehicleFactory
{
  public:
    virtual Vehicle *createVehicle() = 0;
    virtual ~VehicleFactory()
    {
    };
};

class CarFactory : public VehicleFactory{
    public:
    virtual Vehicle *createVehicle() override {
        return new Car();
    }
};


class BikeFactory : public VehicleFactory{
    public:
    virtual Vehicle *createVehicle() override {
        return new Bike();
    }
};

class TrackFactory : public VehicleFactory{
    public:
    virtual Vehicle *createVehicle() override {
        return new Truck();
    }
};



int main() {

Logger* l = Logger::getInstance(); 



l->display();
CarFactory carFactory;
Vehicle* car = carFactory.createVehicle();
car->type();
}
 
  
