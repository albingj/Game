//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"
#include "../../Singleton.h"


SDLPlayer::SDLPlayer() {

    texture = new LTexture();
    setHealth(10);
    //Initialize the offsets
    setMPosX(180);
    setMPosY(560);

    //Initialize the velocity
    setMVelX(10);  //dit is reaction, hoe snel de auto reageert links en rechts

    setMVelY(1);  //set speed (wat dus de Yas is van daar Velocity Y as)



    setWidth(texture->getWidth());
    setHeight(texture->getHeight());

}






void SDLPlayer::LoadImage() {
    texture->loadFromFile("image/cars/Audi.png");
    setWidth(texture->getWidth());
    setHeight(texture->getHeight());
}

void SDLPlayer::Visualize()
{
    texture->render( getMPosX(), getMPosY());
    texture->renderDebug(getMPosX(), getMPosY());

    setWidth(texture->getWidth());
    setHeight(texture->getHeight());
    texture->renderHealth(getMPosX(),getMPosY()+getHeight(), getWidth()/10*getHealth());




}

void SDLPlayer::Free(){
    texture->free();
}


