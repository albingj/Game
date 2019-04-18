//
// Created by admin on 11/03/2019.
//

#include <iostream>
#include "SDLcar.h"
#include "LTexture.h"
#include "../../Game.h"

SDLcar::SDLcar() {

    texture = new LTexture();
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 1;  //dit is reaction, hoe snel de auto reageert
    mVelY = 0;
}


void SDLcar::LoadImage() {
    texture->loadFromFile("image/player.png");
}

void SDLcar::Visualize()
{
    texture->render( 0, 0);
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


