#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Message {
    string sender;
    string text;
};


class Languages{
    public:
    virtual vector<Message> reading() = 0;
};

class English: public Languages{

public: vector<Message> reading() override{
    return {{"Alice", "Hello!"}, {"Bob", "How are you?"}};
    }
};

class Slovak: public Languages{

    public:
    vector<Message> reading() override{
        return {{"Alice", "Ahoj!"}, {"Bob", "Ako sa mas?"}};
    }
};

class WithTranslation:public Languages {
    private:
    Languages* inner;
 public:
    WithTranslation(Languages* l){
        inner = l;
    }

    vector<Message> reading() override {
            vector<Message> msg = inner ->reading();
            for (auto& m :msg)
                m.text = "[translated] " + m.text;
            return msg;
    }   
}; 
class ChatBot {
public:
    vector<Message> getMessages(Languages* language) {
        return language->reading();
    }
};

class Chat {
public:
    void display(const vector<Message>& messages) {
        for (auto& m : messages)
            cout << m.sender << ": " << m.text << "\n";
    }
};

int main() {
    English english;
    WithTranslation translated(&english); // оборачиваем декоратором

    ChatBot bot;
    Chat chat;

    vector<Message> messages = bot.getMessages(&translated);
    chat.display(messages);
}