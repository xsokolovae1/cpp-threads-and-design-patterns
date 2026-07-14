#include <iostream>
#include <string>
using namespace std;

class OldMP3Player {
public:
    void playMP3(const string& filename) {
        cout << "Playing MP3: " << filename << "\n";
    }
};

class OldVideoPlayer {
public:
    void playAVI(const string& filename) {
        cout << "Playing AVI: " << filename << "\n";
    }
};

class IMedia{
    public: 
    virtual void play(const string& filename) = 0;
};


class MusicAdapter : public IMedia {
    OldMP3Player oldp;
    void play(const string& filename){
        oldp.playMP3(filename);    
    }
};
class ViedoAdapter : public IMedia {
    OldVideoPlayer oldv;
    void play(const string& filename){
        oldv.playAVI(filename);    
    }
};


class MediaPlayer {
public:
    void play(IMedia* media, const string& filename) {
        media->play(filename);
    }
};

int main() {
    MediaPlayer player;
    MusicAdapter music;
    ViedoAdapter video;
    player.play(&music, "song.mp3");   // неправильно — не использует старые классы!
    player.play(&video, "video.avi");  // неправильно — не использует старые классы!
}