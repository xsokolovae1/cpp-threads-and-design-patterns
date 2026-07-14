#include <iostream>
#include <string>
using namespace std;


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
    GameLogger() {}                            
    static GameLogger* instance;               

public:
    static GameLogger* getInstance() {
        if (instance == nullptr) {             
            instance = new GameLogger();      
        }
        return instance;                       
    }

    void log(const string& message) {
        cout << "[LOG]: " << message << "\n";
    }
};

GameLogger* GameLogger::instance = nullptr;   


int main() {
    
    EnemyFactory factory;
    Enemy* e1 = factory.create("goblin");
    Enemy* e2 = factory.create("dragon");

   
    GameLogger* logger = GameLogger::getInstance();
    logger->log("Game started");

    e1->attack();
    logger->log("Goblin spawned");

    e2->attack();
    logger->log("Dragon spawned");
}
