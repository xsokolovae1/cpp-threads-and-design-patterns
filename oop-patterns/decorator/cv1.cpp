#include <iostream>
#include <string>
using namespace std;

// ── БАЗОВЫЙ ИНТЕРФЕЙС ───────────────────
class ICoffee {
public:
    virtual string getDescription() = 0;
    virtual float getCost() = 0;
};

// ── ОБЫЧНЫЙ КОФЕ ────────────────────────
class SimpleCoffee : public ICoffee {
public:
    string getDescription() override {
        return "Simple coffee";
    }
    float getCost() override {
        return 1.0;
    }
};

// ── ДЕКОРАТОРЫ ──────────────────────────
class MilkDecorator : public ICoffee {
private:
    ICoffee* inner;  // кого оборачиваем
public:
    MilkDecorator(ICoffee* c) : inner(c) {}
    string getDescription() override {
        return inner->getDescription() + " + milk";
    }
    float getCost() override {
        return inner->getCost() + 0.5;
    }
};

class SugarDecorator : public ICoffee {
private:
    ICoffee* inner;
public:
    SugarDecorator(ICoffee* c) : inner(c) {}
    string getDescription() override {
        return inner->getDescription() + " + sugar";
    }
    float getCost() override {
        return inner->getCost() + 0.2;
    }
};

int main() {
    SimpleCoffee coffee;
    MilkDecorator withMilk(&coffee);
    SugarDecorator withSugar(&withMilk);  // оборачиваем ещё раз!

    cout << withSugar.getDescription() << "\n";
    cout << withSugar.getCost() << "\n";
}