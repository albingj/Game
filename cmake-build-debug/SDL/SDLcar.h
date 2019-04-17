//
// Created by admin on 11/03/2019.
//

#ifndef GAME_SDLCAR_H
#define GAME_SDLCAR_H
#include <stdio.h>
#include <SDL2/SDL_render.h>

#include "../../Car.h"
#include "../../AFactory.h"
#include "LTexture.h"
#include "../../Entity.h"

class SDLcar : public Car, public Entity{

private:
    LTexture* texture;
public:
    SDLcar();
    std::string img;
    void Free();
    void LoadImage();
    void Visualize();



private:

};


#endif //GAME_SDLCAR_H
