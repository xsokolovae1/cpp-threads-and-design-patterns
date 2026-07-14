#include <iostream>
#include <string>
using namespace std;

class ScoreManager {
public:
    int highScore;


    void updateScore(int score) {
        if (score > highScore)
            highScore = score;
        cout << "High score: " << highScore << "\n";
    }

    static ScoreManager* getManager(){
        if(instance == nullptr){
            instance = new ScoreManager();
        }
        return instance;

    }

    private:

    ScoreManager(){
        highScore = 0;
    }
    static ScoreManager* instance; 
};

ScoreManager* ScoreManager::instance = nullptr;

int main() {
    ScoreManager* s = ScoreManager::getManager();
    s->updateScore(100);

}