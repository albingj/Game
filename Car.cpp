//
// Created by admin on 11/03/2019.
//

#include "Car.h"
#include  <iostream>
#include "Singleton.h"


Car::Car() {
//Initialize the velocity
    mVelX = 1;  //dit is reaction, hoe snel de auto reageert



}

void Car::SetSpeed(int velocity){
    this->mVelY==velocity;


}
int Car::GetSpeed(){
    return this->mVelY;
}

void Car::GoLeft() {
    setMPosX(getMPosX() - mVelX);
}
void Car::GoRight() {

    setMPosX(getMPosX() + mVelX);
}
void Car::SetReaction(int reaction){
    this->mVelX==reaction;

}


int Car::getMVelX() const {
    return mVelX;
}

void Car::setMVelX(int mVelX) {
    Car::mVelX = mVelX;
}

int Car::getMVelY() const {
    return mVelY;
}

void Car::setMVelY(int mVelY) {
    Car::mVelY = mVelY;
}

int Car::getRoad() const {
    return road;
}

void Car::setRoad(int road) {
    Car::road = road;
}


void Car::ResetCar(){


    LoadImage();

    this->setRoad(rand() % 4);


    switch(this->getRoad()){

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

    setMPosY( getMPosY() -((rand() % 500)+200));

    setMVelY((rand() % 5)) ;

}



int * Car::getCollisionBox(){
    int collisionBox[4] = {getMPosX(),getMPosY(),getHeight(),getWidth()};

    return collisionBox;
}



void  Car::setWidth(int width){
    Width = width;
}
void  Car::setHeight(int height){
    Height = height;
}
int Car::getWidth(){
    return Width;
}
int Car::getHeight(){
    return Height;
}



void Car::update() {

    setMPosY(getMPosY() + Singleton::getInstance()->getPlayerSpeed() );


}