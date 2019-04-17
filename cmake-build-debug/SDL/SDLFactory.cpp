//
// Created by admin on 11/03/2019.
//

#include "SDLFactory.h"
#include "SDLcar.h"
#include "../../Game.h"
#include "SDLBackground.h"
#include "SDLPlayer.h"

//Using SDL and standard IO

#include <stdio.h>
#include <string>
#include <iostream>

//Scene textures

SDLBackground* background = new SDLBackground();
SDLcar* car = new SDLcar();
SDLPlayer* player = new SDLPlayer();

SDL_Renderer* gRenderer = NULL;

SDLFactory::SDLFactory() {

}

void SDLFactory::CreateWindow() {
    std::cout << ">>>>>> SDL CreateWindow() <<<<<<" << std::endl;
    init();
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
        gWindow = SDL_CreateWindow( "SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
                SDL_SetRenderDrawColor( gRenderer, 96, 128, 255, 255 );

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



void SDLFactory::LoadBackground(){

    background->LoadImage();
    std::cout << ">>>>>> loadImageFromFile Background - done <<<<<<" << std::endl;
}

void SDLFactory::CreatePlayer(){
    player->LoadImage();
    std::cout << ">>>>>> loadImageFromFile car - done <<<<<<" << std::endl;
}



void SDLFactory::close()
{
    //Free loaded images

    background->Free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


void SDLFactory::ClearScreen(){

            //Clear screen
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(gRenderer);
            //std::cout << ">>>>>> SDL ClearScreen()" << std::endl;


}

void SDLFactory::Draw() {

    //Render background texture to screen

    background->Visualize();
    player->Visualize();







}


void SDLFactory::Update(){
    //Update screen, alles op scherm tekenen.
    SDL_RenderPresent(gRenderer);
}



