//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "Entity.h"
#include "Car.h"
#include "Rocket.h"

class Player : public Car{
    int speed=0;


public:
    ~Player();


    void SetReaction(int reaction);
    void addSpeed(bool);
    void removeSpeed(bool);
    void goLeft(bool);
    void goRight(bool);
    void shoot(bool);

    void goUp(bool);
    void goDown(bool);




};


#endif //GAME_PLAYER_H
