    #include <iostream>
    #include <string>
    using namespace std;

    class House {
    public:
        string foundation;
        string walls;
        string roof;
        string windows;
        int rooms;

        void show() {
            cout << "Foundation: " << foundation << "\n";
            cout << "Walls: " << walls << "\n";
            cout << "Roof: " << roof << "\n";
            cout << "Windows: " << windows << "\n";
            cout << "Rooms: " << rooms << "\n";
        }

    };

    class Builder {
        public:
        virtual Builder& setFundation(string f) = 0;
        virtual Builder&  setWalls(string w) = 0;
        virtual Builder&  setRoof(string r) = 0;
        virtual Builder& setWindows(string w) = 0;
        virtual Builder& setRooms(int r) = 0;
        virtual House build() = 0;
    };


    class HouseBuilder : public Builder {
        private:

        House house;
        public:


        virtual Builder& setFundation(string f) {
            house.foundation = f;
            return *this;
        }
        virtual Builder&  setWalls(string w){
            house.walls = w;
            return *this;
        }
        virtual Builder&  setRoof(string r) {
            house.roof = r;
            return *this;
        }
        virtual Builder& setWindows(string w){
            house.windows = w;
            return *this;
        }
        virtual Builder& setRooms(int r){
            house.rooms = r;
            return *this;
        }

        House build(){
            return house;
        }
    };

    int main() {
        House house = HouseBuilder().setFundation("c").setRoof("b").setRooms(4).setWindows("w").setWalls("p").build();

    }