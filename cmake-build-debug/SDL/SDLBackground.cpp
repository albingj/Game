//
// Created by bini on 17-Apr-19.
//

#include "SDLBackground.h"


SDLBackground::SDLBackground() {
    texture = new LTexture();
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 1;  //dit is reaction, hoe snel de auto reageert
    mVelY = 0;
}
void SDLBackground::LoadImage() {
    texture->loadFromFile("image/road.png");
}

void SDLBackground::Visualize()
{
    texture->render( 0, 0);
}

void SDLBackground::Free(){
    texture->free();
}



void SDLBackground::SetSpeed(int velocity){
    this->mVelY==velocity;

}


void SDLBackground::setPosX(int x){

}
void SDLBackground::setPosY(int y) {

}

