//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"
#include "../../Singleton.h"


SDLPlayer::SDLPlayer() {

    texture = new LTexture();

    //Initialize the offsets
    mPosX = 180;
    mPosY = 400;

    //Initialize the velocity
    mVelX = 10;  //dit is reaction, hoe snel de auto reageert links en rechts
    mVelY = 1;   //snelheid auto

}

void SDLPlayer::SetSpeed(int velocity){
    this->mVelY==velocity;


}
int SDLPlayer::GetSpeed(){
    return this->mVelY;
}

void SDLPlayer::addSpeed(bool key){
    if(key){

        this->mVelY +=1;
        Singleton::getInstance()->setPlayerSpeed(this->mVelY) ;
    }
};
void SDLPlayer::removeSpeed(bool key){
    if(key) {
        if(this->mVelY > 0){
            this->mVelY -= 1;
            Singleton::getInstance()->setPlayerSpeed(this->mVelY);
        }

    }
}





void SDLPlayer::goLeft(bool key) {
    if(key){
        if (mPosX!=-50) {
            this->mPosX -= mVelX;
        }
    }
}
void SDLPlayer::goRight(bool key) {
    if(key) {
        if (mPosX!=420) {
            this->mPosX += mVelX;
        }
    }
}
void SDLPlayer::SetReaction(int reaction){
    this->mVelX==reaction;

}

void SDLPlayer::setPosX(int x){

}

void SDLPlayer::setPosY(int y){

}

int SDLPlayer::getX() {return this->mPosX;}
int SDLPlayer::getY() {return this->mPosY;}






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