//
// Created by admin on 11/03/2019.
//

#include <iostream>
#include "SDLcar.h"
#include "LTexture.h"
#include "Game.h"

SDLcar::SDLcar(AFactory* pFactory, SDL_Renderer* renderer) {
    this->pFactory = pFactory;
    this->renderer = renderer;
    LTexture* gCarTexture = new LTexture(pFactory->getGRenderer());
    if( !gCarTexture->loadFromFile( "image/cars/Audi.png" ))
    {
        printf( "Failed to load Foo' texture image!\n" );
    }
    std::cout << ">>>>>> SDLcar done <<<<<<" << std::endl;
}
void SDLcar::vis(){
    int q = 0;
    gCarTexture->render(20, 20, renderer);
    std::cout << ">>>>>> print auto <<<<<<" << std::endl;
}
