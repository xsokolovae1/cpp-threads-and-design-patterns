        #include <iostream>
        #include <string>
        using namespace std;

        class IMessage{
            public:
            virtual void getMessage(string msg) = 0;
        };


        class Message: public IMessage {
        public:
            void getMessage(string msg) override {
                cout<< msg;
            }
        };

        class EncrtypDecorator: public IMessage{
            private:
            IMessage* decorM;

            public:

            EncrtypDecorator(IMessage* m): decorM(m){}
            void getMessage(string text)override{
                    decorM->getMessage(text);
                    cout<<  "encr";
            }
        };

        class TimeDecorator: public IMessage{
            private: 
            IMessage* decorM;
            public:

            TimeDecorator(IMessage* d) : decorM(d){

            }

            void getMessage(string text)override{
                decorM->getMessage(text);
                cout<< "12:00";
            }
        };

        int main() {
            Message msg;
            EncrtypDecorator enmsg(&msg);
            TimeDecorator t(&enmsg);

            t.getMessage("popa))");
        }