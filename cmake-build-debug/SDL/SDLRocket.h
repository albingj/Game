//
// Created by bini on 04-May-19.
//

#ifndef GAME_SDLROCKET_H
#define GAME_SDLROCKET_H


#include "../../Rocket.h"
#include "LTexture.h"

class SDLRocket : public Rocket{
    LTexture* texture;

public:
    SDLRocket();



    void Visualize();
    void LoadImage();
    void Free();

};


#endif //GAME_SDLROCKET_H
