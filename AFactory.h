//
// Created by admin on 11/03/2019.
//


#ifndef GAME_AFACTORY_H
#define GAME_AFACTORY_H


#include <SDL2/SDL_render.h>
#include "Car.h"

class AFactory {
public:
   // AFactory();

   virtual Car* CreateCar() =0;

    virtual void CreateWindow()=0;
    virtual void CreateBackground()=0;
    virtual void Draw()=0;
    virtual void Update()=0;
    virtual SDL_Renderer* getGRenderer()=0;
};

#endif //GAME_AFACTORY_H