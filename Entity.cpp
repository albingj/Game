//
// Created by bini on 17-Apr-19.
//

#include "Entity.h"

int Entity::getMPosX() const {
    return mPosX;
}

void Entity::setMPosX(int mPosX) {
    Entity::mPosX = mPosX;
}

int Entity::getMPosY() const {
    return mPosY;
}

void Entity::setMPosY(int mPosY) {
    Entity::mPosY = mPosY;
}

void  Entity::setWidth(int width){
    Width = width;
}
void  Entity::setHeight(int height){
    Height = height;
}
int Entity::getWidth(){
    return Width;
}
int Entity::getHeight(){
    return Height;
}
