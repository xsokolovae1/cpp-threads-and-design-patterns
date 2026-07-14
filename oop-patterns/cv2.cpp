#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Enemy { string name; int health; };

// ── СТРАТЕГИЯ ──────────────────────────
class IDifficulty {
public:
    virtual vector<Enemy> generate() = 0;
};

class Easy : public IDifficulty {
public:
    vector<Enemy> generate() override {
        cout << "easy";
        return  {{"Goblin", 10}, {"Rat", 5}};
    }
};

class Hard : public IDifficulty {
public:
    vector<Enemy> generate() override {
        cout << "hard ";
        return {{"Dragon", 100}, {"Demon", 80}}
    }
};

// ── ДЕКОРАТОР ──────────────────────────
class WithBoss : public IDifficulty {
    IDifficulty* inner;
public:
    WithBoss(IDifficulty* d) {
        inner = d;
    }
    vector<Enemy> generate() override {
        vector<Enemy> enemies = inner->generate();
        enemies.push_back({"BOSS", 500});
        cout << "Adding boss\n";
        return enemies;
    }
};

// ── GameAI ─────────────────────────────
class GameAI {
public:
    vector<Enemy> generateEnemies(IDifficulty* difficulty) {
        return difficulty->generate();
    }
};

// ── Game ───────────────────────────────
class Game {
public:
    void start(const vector<Enemy>& enemies) {
        for (auto& e : enemies)
            cout << "Spawning " << e.name << " with " << e.health << " hp\n";
    }
};

int main() {
    Easy easy;
    WithBoss withBoss(&easy);

    GameAI ai;
    Game game;

     // ← неправильно
   vector<Enemy> enemies = ai.generateEnemies(&easy); // ← правильно
   game.start(enemies);
}