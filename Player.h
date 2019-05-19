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
    int score=0;
public:
    int getScore() const;

    void setScore(int score);


public:
    ~Player();


    void SetReaction(int reaction);
    void addSpeed(bool);
    void removeSpeed(bool);
    void goLeft(bool);
    void goRight(bool);
    void shoot(bool);
    void Reset();
    void goUp(bool);
    void goDown(bool);




};


#endif //GAME_PLAYER_H
