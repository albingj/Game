//
// Created by bini on 06-May-19.
//

#include <cstdlib>
#include "DropedItem.h"
#include "Singleton.h"


void DropedItem::reset(){


    road = rand() % 4; //randomize on which road it will be rendered
    switch(road){
        case 0:
            setMPosX(35);
            break;

        case 1:
            setMPosX(140);
            break;

        case 2:
            setMPosX(280);
            break;

        case 3:
            setMPosX(420);
            break;
    }

    setMPosY(-(rand() % 500)-200);


    type = (rand() % 10);
    /*
     * 0 = boost
     * 1 = health
     * 2 = rocket
     */

    LoadImage();



}

int DropedItem::getType() const {
    return type;
}

void DropedItem::setType(int type) {
    DropedItem::type = type;
}


void DropedItem::update(){

    setMPosY(getMPosY() + Singleton::getInstance()->getPlayerSpeed() + 2 );

    }

int* DropedItem::getCollisionBox(){
    int* collisionBox = new int[4]; //zet in heap anders zijn we het kwijt

    collisionBox[0] = getMPosX();
    collisionBox[1] = getMPosY();
    collisionBox[2] = getHeight();
    collisionBox[3] = getWidth();


    return collisionBox;
}