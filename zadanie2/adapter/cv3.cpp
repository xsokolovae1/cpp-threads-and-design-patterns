#include <iostream>
#include <string>
using namespace std;

class OldSpeaker {
public:
    void playSound(int volume) {
        cout << "Playing sound at volume: " << volume << "\n";
    }
};

class OldScreen {
public:
    void showPixels(int width, int height) {
        cout << "Screen: " << width << "x" << height << "\n";
    }
};


class IVolume{
    public:
    virtual void changePercent(double volume) = 0;
};

class VolumeAdapter : public IVolume{
    public:
    OldSpeaker oldspeaker;
    
    void changePercent(double volume) override {
        double new_volume = volume * 100;
        cout <<" Changing";
        oldspeaker.playSound(new_volume);

    }
};

class IScreen{
    public:
    virtual void changeResolution(const string& res)= 0;

    
};

class NewScreen : public IScreen {
    private:

    OldScreen oldscreen;
    public:
    void changeResolution(const string& res) override{

        if (res == "HD") {
         oldscreen.showPixels(1280, 720);
        } else {
         oldscreen.showPixels(1920, 1080);
        }

    }
};

class SmartHome {
public:
    void setVolume(IVolume* volume, float volumePercent) {
        volume->changePercent(volumePercent);
    }

    void setResolution(IScreen* screen, const string& res) {
        screen->changeResolution(res);
        
    }
};

int main() {
    SmartHome home;
    NewScreen screen;
    VolumeAdapter volume;
    home.setResolution(&screen, "FHD");
    home.setVolume(&volume, 10);
}