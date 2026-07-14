#include <iostream>
#include <string>
using namespace std;

// ── СЛОЖНЫЕ КЛАССЫ ──────────────────────
class TV {
public:
    void turnOn() { cout << "TV on\n"; }
    void setHDMI() { cout << "HDMI selected\n"; }
};

class SoundSystem {
public:
    void turnOn() { cout << "Sound on\n"; }
    void setVolume(int v) { cout << "Volume: " << v << "\n"; }
};

class Lights {
public:
    void dim() { cout << "Lights dimmed\n"; }
};

// ── ФАСАД ───────────────────────────────
class HomeTheaterFacade {
private:
    TV tv;
    SoundSystem sound;
    Lights lights;
public:
    void watchMovie() {
        cout << "--- Starting movie ---\n";
        lights.dim();
        tv.turnOn();
        tv.setHDMI();
        sound.turnOn();
        sound.setVolume(20);
    }
};

int main() {
    HomeTheaterFacade theater;
    theater.watchMovie();  // одна команда вместо пяти!
}