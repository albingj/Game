//
// Created by bini on 04-May-19.
//

#include <cstdlib>
#include "SDLRocket.h"



SDLRocket::SDLRocket(){
    texture = new LTexture();
}

void SDLRocket::Visualize(){
    texture->render( getMPosX() , getMPosY());
    texture->renderDebug(getMPosX() , getMPosY());
}
void SDLRocket::LoadImage(){
    texture->loadFromFile("image/rocket.png");
    setWidth(texture->getWidth());
    setHeight(texture->getHeight());

}
 void SDLRocket::Free(){
     texture->free();
}