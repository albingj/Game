//
// Created by bini on 17-Apr-19.
//

#include "SDLBackground.h"


SDLBackground::SDLBackground() {
    texture = new LTexture();
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





