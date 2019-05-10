//
// Created by admin on 11/03/2019.
//

#ifndef GAME_SDLFACTORY_H
#define GAME_SDLFACTORY_H


#include <string>
#include <SDL2/SDL_render.h>
#include "../../AFactory.h"
#include "LTexture.h"
extern SDL_Renderer* gRenderer;



class SDLFactory : public AFactory {
//keypress booleans
    bool playerLeft=false,playerRight=false,playerAddSpeed=false,playerRemoveSpeed=false,playerGoUp=false,playerGoDown=false;





public:

//The window renderer
    SDLFactory();
    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;

    std::list<SDLRocket*> lstRocket;


    void CreateWindow() override;

    void LoadBackground();
    void CreatePlayer();
    void ClearScreen();
    void Update();
    void Draw();
    bool Input();

    void Collision();
    void CreateCars();
    void CreateItems();
    void close();
    void shootRocket(bool playerCar, int posX, int posY, int car);


private:

    void init();



};




























#endif //GAME_SDLFACTORY_H
