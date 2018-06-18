#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "audioHandler.hpp"
#include "SDL_mixer.h"

AudioHandler::AudioHandler(string arg_path) {
    path = arg_path;
    music = NULL;
}

bool AudioHandler::loadMusic(const char * s){
    music = Mix_LoadMUS( s );
    // true if succesfully loaded
    if( music == NULL )
    {
        return false;
    }
    return true;
    
}

bool AudioHandler::playMusic(){
    if( Mix_PlayMusic( music, -1 ) == -1 )
    {
        return false;
    }
    return true;
}

bool AudioHandler::stopMusicSmooth(){
    return Mix_FadeOutMusic(750);
}

bool AudioHandler::loadSounds(std::vector<const char *> fileNames){
    
    bool success = true;
        for (int i = 0; i < fileNames.size(); i++){
            const char * s = fileNames[i];
            Mix_Chunk *mc = Mix_LoadWAV(s);
            if (mc== NULL){
                success = false;
            }else{
                effects.insert(pair <const char * , Mix_Chunk *> (s, mc));
            }

        }
    return success;
}

bool AudioHandler::playSound(const char * s){
    if( Mix_PlayChannel( -1, effects[s], 0 ) == -1 )
    {
        return false;
    }
    return true;
}


AudioHandler::~AudioHandler () {
    Mix_FreeMusic(music);
    
    for (const auto& any : effects) {
        Mix_FreeChunk( any.second );
    }


}



