//
// Created by bini on 19-May-19.
//

#ifndef GAME_SDLMENU_H
#define GAME_SDLMENU_H


#include "../../Menu.h"
#include "../../Entity.h"
#include "LTexture.h"

class SDLMenu : public Menu, public Entity {

    LTexture* texture;



public:
    SDLMenu();
    void Free();
    void LoadImage();
    void Visualize();

};


#endif //GAME_SDLMENU_H
