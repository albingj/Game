//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"
#include "../../Singleton.h"
#include "SDLRocket.h"


SDLPlayer::SDLPlayer() {

    texture = new LTexture();
    rocket = new SDLRocket();


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
    texture->renderHealth( getHealth());
    texture->renderItem(getRockets());
    texture->renderScore(getScore());



}

void SDLPlayer::Free(){
    texture->free();
}


