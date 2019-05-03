//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"
#include "../../Singleton.h"


SDLPlayer::SDLPlayer() {

    texture = new LTexture();

    //Initialize the offsets
    setMPosX(180);
    setMPosY(560);

    //Initialize the velocity
    mVelX = 10;  //dit is reaction, hoe snel de auto reageert links en rechts
    mVelY = 1;   //snelheid auto
    speed = 0;



    setWidth(texture->getWidth());
    setHeight(texture->getHeight());




   // this->setCollisionBox(box);


}

void SDLPlayer::SetSpeed(int velocity){
    this->speed==velocity;

}
int SDLPlayer::GetSpeed(){
    return this->speed;
}

void SDLPlayer::addSpeed(bool key){
    if(key){
        if(this->speed < 101) {
            this->speed += mVelY;
            Singleton::getInstance()->setPlayerSpeed(this->speed);

        }

        if(this->speed > 20 && this->speed < 60) {
            setMPosY(getMPosY()-1);

        }




    }
};
void SDLPlayer::removeSpeed(bool key){
    if(key) {
        if(this->speed > 0){
            this->speed -= mVelY;
            Singleton::getInstance()->setPlayerSpeed(this->speed);

        }

        if(getMPosY()<559){

            setMPosY(getMPosY() + 1);
        }



    }
}





void SDLPlayer::goLeft(bool key) {
    if(key){
        if (getMPosX()>30) {
            if ((int)((double)mVelX * (((double)speed/100))<20)){

                setMPosX(getMPosX()-10);
            }else{

                setMPosX(getMPosX()-(int)((double)mVelX * (((double)speed/100))));

            }

        }
    }
}

void SDLPlayer::goRight(bool key) {
    if(key) {
        if (getMPosX()+getWidth()<550) {
            if ((int) ((double) mVelX * (((double) speed / 100)) < 20)) {

                setMPosX(getMPosX()+10);

            } else {

                setMPosX(getMPosX() + (int) ((double) mVelX * (((double) speed / 100))));

            }
        }
    }
}
void SDLPlayer::SetReaction(int reaction){
    this->mVelX==reaction;

}



void SDLPlayer::LoadImage() {
    texture->loadFromFile("image/cars/Audi.png");
}

void SDLPlayer::Visualize()
{
    texture->render( getMPosX(), getMPosY());
    texture->renderDebug(getMPosX(), getMPosY());

    setWidth(texture->getWidth());
    setHeight(texture->getHeight());





}

void SDLPlayer::Free(){
    texture->free();
}


