//
// Created by bini on 19-May-19.
//

#ifndef GAME_SDLTEXT_H
#define GAME_SDLTEXT_H
#include "SDL2/SDL_ttf.h"
#include <string>


class SDLText {

    SDL_Surface* textSurface;
    SDL_Texture* text;
    TTF_Font* font ;



public:
    SDLText();
    ~SDLText();
    void renderHealth(int health);
    void renderItem(int rockets);
    void renderScore(int score);
void renderTopScore(int score);
//Deallocates texture
    void free();

};


#endif //GAME_SDLTEXT_H
