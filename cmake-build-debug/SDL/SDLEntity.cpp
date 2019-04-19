//
// Created by bini on 17-Apr-19.
//

#include "SDLEntity.h"
SDLEntity::SDLEntity()
{

    collisionBox = {};
}




void SDLEntity::setCollisionBox(SDL_Rect box){
    this->collisionBox = box;
}

SDL_Rect SDLEntity::getCollisionBox(){
    return this->collisionBox;
}