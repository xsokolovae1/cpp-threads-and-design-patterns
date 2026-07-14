#include <iostream>
#include <string>
using namespace std;


class Type{
    virtual void getType() = 0;
};

class MySQL : public Type{
    public:
        virtual void getType() override{
            cout << "Connecting to MySQL\n";
            cout << "Port: 3306\n";
        }
};

class PostgreSQL : public Type{
    public:
        virtual void getType() override{
            cout << "Connecting to PostgreSQL\n";
            cout << "Port: 5432\n";
        }
};

class MongoDB : public Type{
    public:
        virtual void getType() override{
            cout << "Connecting to MongoDB\n";
            cout << "Port: 27017\n";
        }
};


class TypeFactory{
    public: virtual Type *createType() = 0;
};

class MySQLFactory: public TypeFactory{
    public:
    virtual Type *createType() override{
        return new MySQL
    }
}

class Database {
public:
    void connect(const string& type) {
        if (type == "mysql") {
            cout << "Connecting to MySQL\n";
            cout << "Port: 3306\n";
        } else if (type == "postgres") {
            cout << "Connecting to PostgreSQL\n";
            cout << "Port: 5432\n";
        } else {
            cout << "Connecting to MongoDB\n";
            cout << "Port: 27017\n";
        }
    }

    void query(const string& sql) {
        cout << "Executing: " << sql << "\n";
    }
};

class App {
public:
    void run() {
        Database* db1 = new Database();
        Database* db2 = new Database();
        Database* db3 = new Database();

        db1->connect("mysql");
        db2->query("SELECT * FROM users");
        db3->query("SELECT * FROM products");
    }
};

int main() {
    App app;
    app.run();
}