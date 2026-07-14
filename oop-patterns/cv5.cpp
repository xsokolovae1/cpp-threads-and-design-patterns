#include <iostream>
#include <string>
using namespace std;

// ── СТРАТЕГИЯ (базовый враг) ────────────
class Enemy {
public:
    virtual void attack() = 0;
};

class Goblin : public Enemy {
public:
    void attack() override {
        cout << "Goblin attacks!\n";
    }
};

class Dragon : public Enemy {
public:
    void attack() override {
        cout << "Dragon attacks!\n";
    }
};


// ── ФАБРИКА ─────────────────────────────
class EnemyFactory {
public:
    Enemy* create(const string& type) {
        if (type == "goblin") return new Goblin();
        else return new Dragon();
    }
};

// ── СИНГЛТОН ────────────────────────────
class GameLogger {
private:
    GameLogger() {}                            // конструктор private!
    static GameLogger* instance;               // единственный экземпляр

public:
    static GameLogger* getInstance() {
        if (instance == nullptr) {             // если ещё не создан
            instance = new GameLogger();       // создаём один раз
        }
        return instance;                       // всегда возвращаем один и тот же
    }

    void log(const string& message) {
        cout << "[LOG]: " << message << "\n";
    }
};

GameLogger* GameLogger::instance = nullptr;    // изначально пусто

// ── MAIN ────────────────────────────────
int main() {
    // фабрика создаёт врагов
    EnemyFactory factory;
    Enemy* e1 = factory.create("goblin");
    Enemy* e2 = factory.create("dragon");

    // синглтон — всегда один и тот же логгер
    GameLogger* logger = GameLogger::getInstance();
    logger->log("Game started");

    e1->attack();
    logger->log("Goblin spawned");

    e2->attack();
    logger->log("Dragon spawned");
}