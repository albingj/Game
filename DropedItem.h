//
// Created by bini on 06-May-19.
//

#ifndef GAME_DROPEDITEM_H
#define GAME_DROPEDITEM_H


#include "Entity.h"

class DropedItem : public Entity {
int road;
    int type;
public:
    int getType() const;

    void setType(int type);
    /*
     * 0 = boost
     * 1 = health
     * 2 = rocket
     */

public:
    void reset();
    DropedItem();

    //For Renderer / SDL
    virtual void Visualize()=0;
    virtual void LoadImage()=0;
    virtual void Free()=0;

    void update();

    int *getCollisionBox();
};


#endif //GAME_DROPEDITEM_H
