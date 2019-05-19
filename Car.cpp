//
// Created by admin on 11/03/2019.
//

#include "Car.h"
#include  <iostream>
#include "Singleton.h"
#include "cmake-build-debug/SDL/SDLRocket.h"


Car::Car() {
//Initialize the velocity

    mVelX = 1;  //dit is reaction, hoe snel de auto reageert
    rockets=1;
    health = 1;
    isPlayer=false;



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
    while (road == oldRoad){
        this->setRoad(rand() % 4);
    }
    switch(this->getRoad()){

        case 0:
            setMPosX(25);
            break;

        case 1:
            setMPosX(160);
            break;

        case 2:
            setMPosX(300);
            break;

        case 3:
            setMPosX(450);
            break;

    }

    oldRoad = road;
    setMPosY(((rand() % 500)) - 600);

    //setMVelY((rand() % 5)) ;
    setMVelY(2);

    this->setRockets(rand() % 2); //of het een raket kan vuren

}

void Car::setVelY(int speed){
    mVelY = speed;
}
int Car::getVelY(){
    return mVelY;
}
void Car::setVelX(int x){
    mVelX = x;
}
int Car::getVelX(){
    return mVelX;
}
int Car::getRockets() const {
    return rockets;
}
void Car::setRockets(int rockets) {
    Car::rockets = rockets;
}
int Car::getHealth() const {
    return health;
}
void Car::setHealth(int health) {
    Car::health = health;

    if (this->health>20){
        this->health=20;
    }
}





int* Car::getCollisionBox(){
    int* collisionBox = new int[4]; //zet in heap anders zijn we het kwijt

    collisionBox[0] = getMPosX();
    collisionBox[1] = getMPosY();
    collisionBox[2] = getHeight();
    collisionBox[3] = getWidth();


    return collisionBox;
}

void Car::update() {

    setMPosY(getMPosY()+ getMVelY() + Singleton::getInstance()->getPlayerSpeed() );


}



bool Car::getIsPlayer() {
    return isPlayer;
}

void Car::setIsPlayer(bool isPlayer) {
    Car::isPlayer = isPlayer;
}

