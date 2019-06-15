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
    ScreenBottom = 800;
    ScreenTop = 0;
    PlayerSpeed=0;
    Score = 0;
    Rocket= 100;
    menu=true;
    CloseGame=false;
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

int Singleton::getRocket() const {
    return Rocket;
}

void Singleton::setRocket(int rocket) {
    Rocket = rocket;
}

int Singleton::getScreenTop() const {
    return ScreenTop;
}

void Singleton::setScreenTop(int screenTop) {
    ScreenTop = screenTop;
}

bool Singleton::isMenu() const {
    return menu;
}

void Singleton::setMenu(bool menu) {
    Singleton::menu = menu;
}

bool Singleton::isCloseGame() const {
    return CloseGame;
}

void Singleton::setCloseGame(bool closeGame) {
    CloseGame = closeGame;
}

int Singleton::getScore() const {
    return Score;
}

void Singleton::setScore(int score) {
    Score = score;
}

