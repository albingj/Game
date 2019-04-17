//
// Created by bini on 17-Apr-19.
//

#include "SDLPlayer.h"


SDLPlayer::SDLPlayer() {
    texture = new LTexture();
}

void SDLPlayer::LoadImage() {
    texture->loadFromFile("image/cars/Audi.png");
}

void SDLPlayer::Visualize()
{
    texture->render( 0, 0);
}

void SDLPlayer::Free(){
    texture->free();
}