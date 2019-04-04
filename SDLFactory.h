//
// Created by admin on 11/03/2019.
//

#ifndef GAME_SDLFACTORY_H
#define GAME_SDLFACTORY_H


#include <string>
#include <SDL2/SDL_render.h>
#include "AFactory.h"
#include "LTexture.h"

class SDLFactory : public AFactory {


public:
//The window renderer
    SDL_Renderer* gRenderer = nullptr;
    SDLFactory();
    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;

    void CreateWindow() override;
    Car *CreateCar() override;
    void CreateBackground();
    void Draw();
    void Update();

    SDL_Renderer* getGRenderer();

private:
    LTexture* gBackgroundTexture = nullptr;

    void close();
    void init();


};




























#endif //GAME_SDLFACTORY_H
