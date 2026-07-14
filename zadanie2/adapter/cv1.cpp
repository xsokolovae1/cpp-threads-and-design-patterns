#include <iostream>
#include <string>
using namespace std;

// ── ЕВРОПЕЙСКАЯ РОЗЕТКА (старый класс) ──
class EuropeanSocket {
public:
    void plugIn220V() {
        cout << "European socket: 220V connected\n";
    }
};

// ── ИНТЕРФЕЙС АМЕРИКАНСКОЙ РОЗЕТКИ ──────
class IAmericanSocket {
public:
    virtual void plugIn110V() = 0;
};

// ── АДАПТЕР ─────────────────────────────
class SocketAdapter : public IAmericanSocket {
private:
    EuropeanSocket european;  // просто объект, без звёздочки!
public:
    void plugIn110V() override {
        cout << "Adapter: converting 110V to 220V\n";
        european.plugIn220V();  // точка, не стрелочка!
    }
};

int main() {
    SocketAdapter adapter;
    adapter.plugIn110V();
}