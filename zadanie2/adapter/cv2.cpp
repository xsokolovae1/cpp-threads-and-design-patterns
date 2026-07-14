    #include <iostream>
    #include <string>
    using namespace std;

    class OldPayment {
    public:
        void makePayment(int amountInCents) {
            cout << "Paid: " << amountInCents << " cents\n";
        }
    };

    class IPayment {
        public:
            virtual void newPayment(float newAmount) = 0; 
    };

    class Euro : public IPayment {
        private:
            OldPayment oldpayment;
        public:
            void newPayment(float amountInEuros) override {
                cout << "Convert to euros";
                float new1 = amountInEuros*100;
                oldpayment.makePayment(new1);
            }
    };

    class App {


    public:
        void pay(IPayment* payment, float amount) {
            payment->newPayment(amount);
        }
    };

    int main() {

        Euro euro;
        euro.newPayment(100);

        App app;
        app.pay(&euro, 9.99);   // вот так используй!
        app.pay(&euro, 49.99);
    }