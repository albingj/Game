//
// Created by bini on 04-May-19.
//

#ifndef GAME_ROCKET_H
#define GAME_ROCKET_H


#include "Entity.h"

class Rocket : public Entity{
    int aantal;
    int Width, Height;
    int velocity;
public:
    Rocket();
    int getAantal();
    void setAantal(int);
    int getWidth();
    int getHeight();
    void setWidth(int);
    void setHeight(int);
    void update();

};


#endif //GAME_ROCKET_H
