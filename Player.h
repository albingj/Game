//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "Entity.h"

class Player{
public:
    virtual ~Player();
    virtual void SetSpeed()=0;
    virtual void setPosX()=0;
    virtual void setPosY()=0;
    virtual int GetSpeed()=0;
    virtual void SetReaction(int reaction)=0;
    virtual void setPosX(int x)=0;
    virtual void setPosY(int y)=0;

};


#endif //GAME_PLAYER_H
