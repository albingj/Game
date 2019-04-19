//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLPLAYER_H
#define GAME_SDLPLAYER_H

#include "../../Entity.h"
#include "../../Player.h"
#include "LTexture.h"
#include "SDLcar.h"

class SDLPlayer : public SDLcar ,public Player {
    LTexture* texture;

    //The X and Y offsets of the car
    int mPosX, mPosY;
    SDL_Rect box;

    //The velocity of the car
    int mVelX, mVelY;
    int speed;


   // SDL_Rect collisionBox;

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
    int getX();
    int getY();









};


#endif //GAME_SDLPLAYER_H
