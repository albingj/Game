//
// Created by admin on 11/03/2019.
//

#include <iostream>
#include "SDLcar.h"
#include "LTexture.h"
#include "../../Game.h"
#include "../../Singleton.h"

SDLcar::SDLcar() {

    texture = new LTexture();
    //Initialize the offsets

    //mPosX = (rand() % 400);
    //mPosY = 0;


    box.w = texture->getWidth();
    box.h = texture->getHeight();
    box.x = 0;
    box.y  =0;
    setCollisionBox(box);

    SDLcar::ResetCar();







    //Initialize the velocity
    mVelX = 1;  //dit is reaction, hoe snel de auto reageert




}


void SDLcar::LoadImage() {

    std::string car[9] = {
            "Audi.png",
            "Ambulance.png",
            "Black_viper.png",
            "Car.png"
            , "Mini_truck.png"
            , "Mini_van.png"
            , "Police.png"
            , "taxi.png"
            , "truck.png"
    };
    texture->loadFromFile("image/cars/"+ car[(rand() % 9)]);





}

void SDLcar::Visualize()
{

    box.y +=(mVelY + Singleton::getInstance()->getPlayerSpeed()) ;
    setCollisionBox(box);
    texture->render( box.x, box.y);

    texture->renderDebug(box.x, box.y);

}

void SDLcar::Free(){
    texture->free();
}


void SDLcar::SetSpeed(int velocity){
    this->mVelY==velocity;

}
int SDLcar::GetSpeed(){
    return this->mVelY;
}

void SDLcar::GoLeft() {
    this->mPosX -= mVelX;
}
void SDLcar::GoRight() {
    this->mPosX += mVelX;
}
void SDLcar::SetReaction(int reaction){
    this->mVelX==reaction;

}

void SDLcar::setPosX(int x){

}

void SDLcar::setPosY(int y){

}


void SDLcar::ResetCar(){

   // this->Free();

    this->LoadImage();


    road = (rand() % 4);


    switch(road){

        case 0:
            box.x =35;
            break;

        case 1:
            box.x =140;
            break;

        case 2:
            box.x =280;
            break;

        case 3:
            box.x =420;
            break;

    }






    box.y = -((rand() % 500)+200);

    setCollisionBox(box);
    mVelY =((rand() % 5)) ;
}

