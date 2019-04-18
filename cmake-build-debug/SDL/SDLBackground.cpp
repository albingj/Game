//
// Created by bini on 17-Apr-19.
//

#include "SDLBackground.h"
#include "../../Singleton.h"

SDLBackground::SDLBackground() {

    texture = new LTexture();
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;


    //The background scrolling offset
    scrollingOffset = 0;


}

void SDLBackground::LoadImage() {
    texture->loadFromFile("image/road.png");
}

void SDLBackground::Visualize()
{
   // texture->render( scrollingOffset + Singleton::getInstance()->getPlayerSpeed(), 0 );
    //texture->render( scrollingOffset + texture->getWidth(), 0 );

    if (scrollingOffset<texture->getHeight()){
        scrollingOffset+=Singleton::getInstance()->getPlayerSpeed()/2;
    }else{
        scrollingOffset=0;
    }

    texture->render( 0, scrollingOffset - texture->getHeight());
    texture->render( 0, scrollingOffset);
    texture->render( 0, scrollingOffset + texture->getHeight());



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

