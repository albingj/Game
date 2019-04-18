//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "Entity.h"

class Player{
public:
    virtual ~Player();
    virtual int GetSpeed()=0;
    virtual void SetReaction(int reaction)=0;
    virtual void addSpeed(bool) =0;
    virtual void removeSpeed(bool)=0;
    virtual void goLeft(bool)=0;
    virtual void goRight(bool)=0;


};


#endif //GAME_PLAYER_H
