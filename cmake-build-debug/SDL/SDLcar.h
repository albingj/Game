//
// Created by admin on 11/03/2019.
//

#ifndef GAME_SDLCAR_H
#define GAME_SDLCAR_H
//#include <stdio.h>
#include <SDL2/SDL_render.h>

#include "../../Car.h"
#include "../../AFactory.h"
#include "LTexture.h"

class SDLcar : public Car{

private:
    LTexture* texture;
    LTexture* healthBar;
public:

public:
    SDLcar();
    std::string img;
    void Free();
    void LoadImage();
    void Visualize();


private:

};


#endif //GAME_SDLCAR_H
