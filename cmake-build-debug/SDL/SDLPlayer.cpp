//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"
#include "../../Singleton.h"


SDLPlayer::SDLPlayer() {

    texture = new LTexture();

    //Initialize the offsets
    mPosX = 180;
    mPosY = 560;

    //Initialize the velocity
    mVelX = 10;  //dit is reaction, hoe snel de auto reageert links en rechts
    mVelY = 1;   //snelheid auto
    speed = 0;


    box.x = mPosX;
    box.y = mPosY;
    box.w = texture->getWidth();
    box.h = texture->getHeight();



    setCollisionBox(box);


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
            this->mPosY -=1;

            box.y  -=1;
            setCollisionBox(box);
        }




    }
};
void SDLPlayer::removeSpeed(bool key){
    if(key) {
        if(this->speed > 0){
            this->speed -= mVelY;
            Singleton::getInstance()->setPlayerSpeed(this->speed);

        }

        if(mPosY<559){
            this->mPosY +=1;
            box.y  +=1;
            setCollisionBox(box);
        }



    }
}





void SDLPlayer::goLeft(bool key) {
    if(key){
        if (mPosX>=-50) {
            if ((int)((double)mVelX * (((double)speed/100))<20)){
                this->mPosX -= 10;
                box.x  -=10;
                setCollisionBox(box);
            }else{
                this->mPosX -= (int)((double)mVelX * (((double)speed/100)));
                box.x  -= (int)((double)mVelX * (((double)speed/100)));
                setCollisionBox(box);
            }

        }
    }
}

void SDLPlayer::goRight(bool key) {
    if(key) {
        if ((int)((double)mVelX * (((double)speed/100))<20)){
            this->mPosX += 10;
            box.x  +=10;
            setCollisionBox(box);
        }else{
            this->mPosX += (int)((double)mVelX * (((double)speed/100)));
            box.x  += (int)((double)mVelX * (((double)speed/100)));
            setCollisionBox(box);
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
    texture->renderDebug(mPosX,mPosY);

    box.w = texture->getWidth();
    box.h = texture->getHeight();
    setCollisionBox(box);



}

void SDLPlayer::Free(){
    texture->free();
}