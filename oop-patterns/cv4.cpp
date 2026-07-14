#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Product {
    string name;
    float price;
};

class Category{
    public: 
    virtual vector<Product> fetching()=0;
};

class Electronics: public Category {
    public:

    vector <Product> fetching() override {
         cout << "Fetching electronics\n";

         return {{"Laptop", 1000}, {"Phone", 500}};
    }
};
class Clothes: public Category {
    public:

    vector <Product> fetching() override {
         cout << "Fetching clothes\n";

         return {{"Shirt", 20}, {"Pants", 40}};
    }
};

class WithDiscount : public Category {
    private:
    Category *inner_category;

    public:
      WithDiscount(Category * c){
         inner_category = c;
      }

      vector<Product> fetching() override{
        vector<Product> products = inner_category ->fetching();
        for(auto& p :products)
            p.price = p.price * 0.9;
      }
};


class Shop {
public:
    vector<Product> getProducts(Category* categories) {
 
        return categories->fetching();
      }
};

class Cart {
public:
    void display(const vector<Product>& products) {
        for (auto& p : products)
            cout << p.name << ": " << p.price << "$\n";
    }
};

int main() {
    Clothes clothes;
    Electronics electronics;

    Shop shop;
    Cart cart;

    vector<Product> products = shop.getProducts(&clothes);
    cart.display(products);


    
    
}