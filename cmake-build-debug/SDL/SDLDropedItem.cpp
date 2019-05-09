//
// Created by bini on 06-May-19.
//

#include "SDLDropedItem.h"


SDLDropedItem::SDLDropedItem() {

    texture = new LTexture();

}


void SDLDropedItem::LoadImage() {
    switch (getType()){
        case 0:
            texture->loadFromFile("image/Audi.png");
            break;

        case 1:
            texture->loadFromFile("image/heart.png");
            break;

        case 2:
            texture->loadFromFile("image/rocket.png");
            break;

    }

    setWidth(texture->getWidth());
    setHeight(texture->getHeight());
}

void SDLDropedItem::Visualize()
{
    texture->render( getMPosX(), getMPosY());
    texture->renderDebug(getMPosX(), getMPosY());

}

void SDLDropedItem::Free(){
    texture->free();
}