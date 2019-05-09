//
// Created by bini on 06-May-19.
//

#include <cstdlib>
#include "DropedItem.h"


void DropedItem::reset(){
    setMPosY(0);
    type = (rand() % 3);
    /*
     * 0 = boost
     * 1 = health
     * 2 = rocket
     */

    LoadImage();


    int road = (rand() % 4);

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





}

int DropedItem::getType() const {
    return type;
}

void DropedItem::setType(int type) {
    DropedItem::type = type;
}
