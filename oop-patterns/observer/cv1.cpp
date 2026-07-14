#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ── НАБЛЮДАТЕЛЬ ─────────────────────────
class IObserver {
public:
    virtual void update(const string& event) = 0;
};

// ── СУБЪЕКТ (за кем следят) ─────────────
class Game {
private:
    vector<IObserver*> observers;  // список подписчиков
public:
    void subscribe(IObserver* o) {
        observers.push_back(o);    // добавить подписчика
    }
    void notify(const string& event) {
        for (auto& o : observers)
            o->update(event);      // оповестить всех
    }
    void playerDied() {
        cout << "Player died!\n";
        notify("death");           // что-то случилось — оповещаем
    }
    void levelUp() {
        cout << "Level up!\n";
        notify("levelup");
    }
};

// ── КОНКРЕТНЫЕ НАБЛЮДАТЕЛИ ──────────────
class ScoreSystem : public IObserver {
public:
    void update(const string& event) override {
        if (event == "levelup")
            cout << "ScoreSystem: +100 points!\n";
    }
};

class SoundSystem : public IObserver {
public:
    void update(const string& event) override {
        if (event == "death")
            cout << "SoundSystem: playing death sound\n";
        if (event == "levelup")
            cout << "SoundSystem: playing levelup sound\n";
    }
};

int main() {
    Game game;
    ScoreSystem score;
    SoundSystem sound;

    game.subscribe(&score);  // подписываем
    game.subscribe(&sound);

    game.playerDied();
    game.levelUp();
}