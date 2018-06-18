#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "audioHandler.hpp"
#include "SDL_mixer.h"
#include "SDL.h"

using namespace std;

//SAMPLE

int main(){
    
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    
    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;
    
    //The image we will load and show on the screen
    //SDL_Surface* gHelloWorld = NULL;
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL MUSIC TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        cout<<("openaudioError\n");
        success = false;
    }
    
    

    string p = "/pathy";
    
    AudioHandler a(p);
    
    a.loadMusic("caveCrazySmooth.wav");
    
    std::vector<const char *> s;
    s.push_back("pickUp.wav");
    s.push_back("machineGun.wav");
    
    a.loadSounds(s);
    a.playMusic();
    SDL_Delay(5000);
    
    
    
    a.playSound("pickUp.wav");
    
    SDL_Delay(2000);
    
    a.playSound("machineGun.wav");
    SDL_Delay(5000);
    a.stopMusicSmooth();
    SDL_Delay(1500);
    
    SDL_FreeSurface(gScreenSurface);
    
    Mix_CloseAudio();
    SDL_Quit();
    
}
