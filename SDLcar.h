//
// Created by admin on 11/03/2019.
//

#ifndef GAME_SDLCAR_H
#define GAME_SDLCAR_H
#include <stdio.h>
#include <SDL2/SDL_render.h>

#include "Car.h"
#include "AFactory.h"
#include "LTexture.h"

class SDLcar : public Car{

private:
    SDL_Renderer* renderer = nullptr;
    LTexture* gCarTexture = nullptr;
    AFactory* pFactory = nullptr;
public:
    SDLcar( AFactory *pFactory, SDL_Renderer* renderer);
    void vis();
    std::string img;
private:

};


#endif //GAME_SDLCAR_H
