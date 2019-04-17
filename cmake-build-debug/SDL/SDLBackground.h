//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_SDLBACKGROUND_H
#define GAME_SDLBACKGROUND_H

#include "../../Background.h"
#include "../../Entity.h"
#include "LTexture.h"

class SDLBackground:  public Background, public Entity{
    LTexture* texture;
public:
    SDLBackground();
    void Free();
    void LoadImage();
    void Visualize();
    void Movebackground(int s);
};


#endif //GAME_SDLBACKGROUND_H
