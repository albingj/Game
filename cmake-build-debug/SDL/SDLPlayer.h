//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLPLAYER_H
#define GAME_SDLPLAYER_H


#include "../../Entity.h"
#include "../../Player.h"
#include "LTexture.h"
#include "../../Car.h"

class SDLPlayer :public Entity, public Car {
    LTexture* texture;

    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;


public:
    SDLPlayer();

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




};


#endif //GAME_SDLPLAYER_H
