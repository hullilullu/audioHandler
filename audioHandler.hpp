
#ifndef AUDIOHANDLER_FILE

#define AUDIOHANDLER_FILE

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "audioHandler.hpp"
#include "SDL_mixer.h"


using namespace std;

class AudioHandler {
public:
    AudioHandler(string arg_path);
    ~AudioHandler ();
    bool close();
    bool loadSounds(vector<const char *>);
    bool playSound(const char *);
    bool loadMusic(const char *);
    bool playMusic();
    bool stopMusicSmooth();
    //bool stopMusic();
private:
    string path;
    string effects_name, music_name;
    Mix_Music *music;
    
    //The sound effects that will be used, mapped to filename
    map<const char *, Mix_Chunk *> effects;
};

#endif