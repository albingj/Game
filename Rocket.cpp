//
// Created by bini on 04-May-19.
//

#include "Rocket.h"
#include "Singleton.h"


Rocket::Rocket() {

    velocity=2;
};



void Rocket::setWidth(int w){
    Width = w;
}
void Rocket::setHeight(int h){
    Height = h ;
}

int Rocket::getWidth(){
    return Width;
}
int Rocket::getHeight(){
    return Height;
}

void Rocket::update(){

    if (direction){//if true then player shot it

        setMPosY(getMPosY()- velocity - Singleton::getInstance()->getPlayerSpeed());

    }else{

        setMPosY(getMPosY()+ velocity + Singleton::getInstance()->getPlayerSpeed());

    }


}

bool Rocket::isDirection() const {
    return direction;
}

void Rocket::setDirection(bool direction) {
    Rocket::direction = direction;
}

int Rocket::getVelocity() const {
    return velocity;
}

void Rocket::setVelocity(int velocity) {
    Rocket::velocity = velocity;
}


int* Rocket::getCollisionBox(){
    int* collisionBox = new int[4]; //zet in heap anders zijn we het kwijt

    collisionBox[0] = getMPosX();
    collisionBox[1] = getMPosY();
    collisionBox[2] = getHeight();
    collisionBox[3] = getWidth();


    return collisionBox;
}