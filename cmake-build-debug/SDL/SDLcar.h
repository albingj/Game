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
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;
public:
    SDLcar();
    std::string img;
    void Free();
    void LoadImage();
    void Visualize();

    void setPosX(int x);
    void setPosY(int y);

    void SetSpeed(int velocity);

    void SetReaction(int reaction);
    int GetSpeed();
    void GoLeft();
    void GoRight();



private:

};


#endif //GAME_SDLCAR_H
