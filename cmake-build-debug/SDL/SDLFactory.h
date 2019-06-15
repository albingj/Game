//
// Created by admin on 11/03/2019.
//

#ifndef GAME_SDLFACTORY_H
#define GAME_SDLFACTORY_H


#include <string>
#include <SDL2/SDL_render.h>
#include "LTexture.h"
#include "../../AFactory.h"

extern SDL_Renderer* gRenderer;

class SDLFactory : public AFactory {

//keypress booleans
    bool playerLeft=false,playerRight=false,playerAddSpeed=false,playerRemoveSpeed=false,playerGoUp=false,playerGoDown=false;
    void init();

public:
//The window renderer
    SDLFactory();
    ~SDLFactory();
    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;
    void CreateSDLWindow();
    void ClearScreen();
    bool Input();
    void close();
};




#endif //GAME_SDLFACTORY_H
