//
// Created by admin on 11/03/2019.
//

#include <iostream>
#include "SDLcar.h"
#include "LTexture.h"
#include "../../Game.h"

SDLcar::SDLcar() {

    texture = new LTexture();
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