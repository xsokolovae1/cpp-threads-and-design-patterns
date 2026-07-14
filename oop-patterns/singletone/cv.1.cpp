#include <iostream>
#include <string>
using namespace std;

class Config {

private:
    Config(const string& name, const string& ver) {
        appName = name;
        version = ver;
    }
    static Config* config;

public:
    string appName;
    string version;

    static Config* getConfig() {
        if(config == nullptr){
            config = new Config("MyApp", "1.0");
        }
        return config;
    }

    void show(){
        cout << "App: " << appName << " v" << version << "\n";
    }

};

Config* Config::config = nullptr;


int main() {
    Config* c = Config::getConfig();
    

    c->show();
   
}
