//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"


SDLPlayer::SDLPlayer() {
    texture = new LTexture();

    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 1;  //dit is reaction, hoe snel de auto reageert
    mVelY = 0;

}

void SDLPlayer::SetSpeed(int velocity){
    this->mVelY==velocity;

}
int SDLPlayer::GetSpeed(){
    return this->mVelY;
}

void SDLPlayer::GoLeft() {
    this->mPosX -= mVelX;
}
void SDLPlayer::GoRight() {
    this->mPosX += mVelX;
}
void SDLPlayer::SetReaction(int reaction){
    this->mVelX==reaction;

}

void SDLPlayer::setPosX(int x){

}

void SDLPlayer::setPosY(int y){

}



void SDLPlayer::LoadImage() {
    texture->loadFromFile("image/cars/Audi.png");
}

void SDLPlayer::Visualize()
{
    texture->render( mPosX, mPosY);
}

void SDLPlayer::Free(){
    texture->free();
}