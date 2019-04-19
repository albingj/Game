//
// Created by bini on 18-Apr-19.
//

#include "Singleton.h"

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;



Singleton* Singleton::getInstance()
{


    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{
    ScreenBottom = 750;
    PlayerSpeed=0;



}

void Singleton::setPlayerSpeed(int Speed){
   this->PlayerSpeed = Speed;
}
int Singleton::getPlayerSpeed(){
    return this->PlayerSpeed;
}

int Singleton::getScreenBottom(){
    return this->ScreenBottom;
}