//
// Created by bini on 04-May-19.
//

#ifndef GAME_ROCKET_H
#define GAME_ROCKET_H


#include "Entity.h"

class Rocket : public Entity{

    int Width, Height;
    int velocity;
public:
    int getVelocity() const;

    void setVelocity(int velocity);

private:
    bool direction;
public:
    bool isDirection() const;

    void setDirection(bool direction);

public:
    Rocket();
    int getAantal();
    void setAantal(int);
    int getWidth();
    int getHeight();
    void setWidth(int);
    void setHeight(int);
    void update();
    int *getCollisionBox();
    //For Renderer / SDL
    virtual void Visualize()=0;
    virtual void LoadImage()=0;
    virtual void Free()=0;

private:




};


#endif //GAME_ROCKET_H
