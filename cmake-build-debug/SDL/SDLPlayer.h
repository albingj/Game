//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLPLAYER_H
#define GAME_SDLPLAYER_H

#include "../../Entity.h"
#include "../../Player.h"
#include "LTexture.h"
#include "SDLcar.h"

class SDLPlayer :  public Player  {
    LTexture* texture;

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



    SDL_Rect getCollisionBox();

    void setCollisionBox(const SDL_Rect &collisionBox);

    void ResetCar();

};


#endif //GAME_SDLPLAYER_H
