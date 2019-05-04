//
// Created by bini on 04-May-19.
//

#include "Rocket.h"
#include "Singleton.h"


Rocket::Rocket() {
    int aantal = 0;
    velocity=2;
};

int Rocket::getAantal(){
    return aantal;
}
void Rocket::setAantal(int t){
    aantal = aantal + t;
}

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
    setMPosY(getMPosY()+ velocity + Singleton::getInstance()->getPlayerSpeed());
}