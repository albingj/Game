//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLENTITY_H
#define GAME_SDLENTITY_H

#include <SDL2/SDL_rect.h>
#include "../../Entity.h"

class SDLEntity : public Entity{

    SDL_Rect collisionBox;


public:

    SDLEntity();


    void setCollisionBox(SDL_Rect box);
    SDL_Rect getCollisionBox();




    void setPosX(int x) = 0;
    void setPosY(int y) = 0;
    //void SetSpeed(int velocity) = 0;



};


#endif //GAME_SDLENTITY_H
