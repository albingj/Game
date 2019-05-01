//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLBACKGROUND_H
#define GAME_SDLBACKGROUND_H

#include "../../Background.h"
#include "../../Entity.h"
#include "LTexture.h"

class SDLBackground:  public Background, public Entity{
    LTexture* texture;
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;
    int scrollingOffset;

public:
    SDLBackground();
    void Free();
    void LoadImage();
    void Visualize();

    void setPosX(int x);
    void setPosY(int y);
    void SetSpeed(int velocity);
    void VisualizeSpeed();


};


#endif //GAME_SDLBACKGROUND_H
