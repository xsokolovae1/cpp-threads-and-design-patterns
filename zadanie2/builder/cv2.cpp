#include <iostream>
#include <string>
using namespace std;


class Pizza {
public:
    string size;
    string dough;
    string sauce;
    string topping;

    void show() {
        cout << "Size: " << size << "\n";
        cout << "Dough: " << dough << "\n";
        cout << "Sauce: " << sauce << "\n";
        cout << "Topping: " << topping << "\n";
    }
};

class PizzaBuilder{
    private:
    Pizza pizza; 
    public:
        PizzaBuilder& setSize(const string&  size){
            pizza.size = size;
           return *this;
        }

        PizzaBuilder& setDough( const string& dough){
            pizza.dough = dough;
            return *this;
        }

        PizzaBuilder& setSauce(const string& sauce){
            pizza.sauce = sauce;
            return *this;
        }

        PizzaBuilder& setTopping(const string& topping){
            pizza.topping = topping;
            return *this;
        }

        Pizza build(){
            return pizza;
        }
};

int main() {
    Pizza pizza = PizzaBuilder()
        .setSize("large")
        .setDough("thin")
        .setTopping("cheese")
        .setSauce("tomato")
        .build();
   
    pizza.show();
}