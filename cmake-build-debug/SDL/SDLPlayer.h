//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLPLAYER_H
#define GAME_SDLPLAYER_H


#include "../../Entity.h"
#include "../../Player.h"
#include "LTexture.h"
#include "../../Car.h"

class SDLPlayer :public Entity, public Car,public Player {
    LTexture* texture;

    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;


public:
    SDLPlayer();



    //Entity
    void Free();
    void LoadImage();
    void Visualize();

    void setPosX(int x);
    void setPosY(int y);



    //car
    void SetSpeed(int velocity);




    //player
    int GetSpeed();
    void SetReaction(int reaction);

    void addSpeed(bool);
    void removeSpeed(bool);
    void goLeft(bool);
    void goRight(bool);










};


#endif //GAME_SDLPLAYER_H
