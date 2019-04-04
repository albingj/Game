//
// Created by admin on 11/03/2019.
//

#include "SDLFactory.h"
#include "SDLcar.h"
#include "Game.h"

//Using SDL and standard IO

#include <stdio.h>
#include <string>
#include <iostream>

//Scene textures

SDLFactory::SDLFactory() {

}

SDL_Renderer* SDLFactory::getGRenderer() {
    return gRenderer;
}

void SDLFactory::CreateWindow() {
    std::cout << ">>>>>> SDL CreateWindow() <<<<<<" << std::endl;
    init();
}


Car * SDLFactory::CreateCar() {
    return new SDLcar(this, gRenderer);
}

void SDLFactory::CreateBackground(){



    //Load background texture
    gBackgroundTexture = new LTexture(gRenderer);
    if( !gBackgroundTexture->loadFromFile( "image/road.png") )
    {
        printf( "Failed to load background texture image!\n" );

    }
    std::cout << ">>>>>> loadFromFile Background - done <<<<<<" << std::endl;
}


void SDLFactory::init(){
    std::cout << ">>>>>> SDL init() <<<<<<" << std::endl;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );

    }
    else
    {
        std::cout << ">>>>>> SDL init - no error" << std::endl;
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );

        }
        else
        {
            std::cout << ">>>>>> SDL init - Create renderer for window" << std::endl;
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );

            }
            else
            {
                std::cout << ">>>>>> SDL init - Initialize renderer color" << std::endl;
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );

                }
            }
        }
    }
    std::cout << ">>>>>> SDL init - done <<<<<<" << std::endl;

}


void SDLFactory::close()
{
    //Free loaded images

    gBackgroundTexture->free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


void SDLFactory::Draw(){





            //Clear screen
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(gRenderer);

            //Render background texture to screen
            gBackgroundTexture->render(0, 0, gRenderer);

        std::cout << ">>>>>> SDL Draw()" << std::endl;


}

void SDLFactory::Update(){
    //Update screen

    SDL_RenderPresent(gRenderer);
    std::cout << ">>>>>> SDL update() <<<<<<" << std::endl;
}



