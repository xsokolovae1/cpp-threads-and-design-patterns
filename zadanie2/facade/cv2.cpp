#include <iostream>
#include <string>
using namespace std;

class Database {
public:
    void connect() { cout << "Database connected\n"; }
    void query(const string& sql) { cout << "Query: " << sql << "\n"; }
    void disconnect() { cout << "Database disconnected\n"; }
};

class Logger {
public:
    void startLog() { cout << "Logger started\n"; }
    void log(const string& msg) { cout << "Log: " << msg << "\n"; }
    void stopLog() { cout << "Logger stopped\n"; }
};

class EmailService {
public:
    void connect() { cout << "Email connected\n"; }
    void send(const string& msg) { cout << "Email sent: " << msg << "\n"; }
    void disconnect() { cout << "Email disconnected\n"; }
};


class Facade {
    private:

    Logger logger;
    EmailService email;
    Database db;

    public:
    void start(){
      logger.startLog();
      db.connect();
      db.query("SELECT * FROM users");
      email.connect();
        email.send("New user registered");
         email.disconnect();
         db.disconnect();
      logger.stopLog();
    }


};
int main() {
    Facade facade;

    facade.start();
  


}