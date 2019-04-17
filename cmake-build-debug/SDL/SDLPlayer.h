//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLPLAYER_H
#define GAME_SDLPLAYER_H


#include "../../Entity.h"
#include "../../Player.h"
#include "LTexture.h"

class SDLPlayer:public Player , public Entity {
    LTexture* texture;
public:
    SDLPlayer();
    void Free();
    void LoadImage();
    void Visualize();
};


#endif //GAME_SDLPLAYER_H
