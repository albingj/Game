//
// Created by admin on 11/03/2019.
//
//
// Created by admin on 11/03/2019.
//

#ifndef GAME_CAR_H
#define GAME_CAR_H


#include <SDL2/SDL_rect.h>
#include "Entity.h"
#include "Rocket.h"

class Car :public Entity{

    int rockets;
    int health;
    int mVelX, mVelY;

    int Height, Width;

    //car.h
    int road=0;
    int oldRoad;

public:
    int getHealth() const;
    void setHealth(int health);
    int getRockets() const;
    void setRockets(int rockets);

    Car();
    int GetSpeed();
    void SetReaction(int reaction);
    void GoLeft();
    void GoRight();

    void SetSpeed(int velocity);

    int getMVelX() const;

    void setMVelX(int mVelX);

    int getMVelY() const;

    void setMVelY(int mVelY);

    int getRoad() const;

    void setRoad(int road);




    void ResetCar();

    int * getCollisionBox();


    void setVelY(int speed);
    int getVelY();
    void setVelX(int speed);
    int getVelX();

    void setCollisionBox( int collisionbox[4]);


    void update();


    //For Renderer / SDL
    virtual void Visualize()=0;
    virtual void LoadImage()=0;
    virtual void Free()=0;

};


#endif //GAME_CAR_H

