//
// Created by admin on 11/03/2019.
//



#include <string>
#include <sstream>
#include "SDLFactory.h"

//#include "../../Game.h"
#include "../../Singleton.h"
#include "SDLTimer.h"


//Using SDL and standard IO

//#include <stdio.h>
SDLFactory::SDLFactory() {

}

SDLFactory::~SDLFactory() {

}

SDL_Renderer* gRenderer = NULL;
//Frames maximum
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;


void SDLFactory::CreateSDLWindow() {
    init();
}
void SDLFactory::init(){


    TTF_Init();
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        //printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );

    }
    else
    {

        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            //printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 569, 850, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            //printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );

        }
        else
        {

            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );



            //Set text color as black
            //SDL_Color textColor = { 0, 0, 0, 255 };

            if( gRenderer == NULL )
            {
                //printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );

            }
            else
            {

                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 96, 128, 255, 255 );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    //printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );

                }
            }
        }
    }


}
void SDLFactory::close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
void SDLFactory::ClearScreen(){
    SDL_RenderPresent(gRenderer);
    //Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    //std::cout << ">>>>>> SDL ClearScreen()" << std::endl;

}


//Zolang stop op false blijft gaan we alles blijven loopen.
//Als we X drukken stopt het spel
bool SDLFactory::Input()
{


    //The frames per second timer
    SDLTimer fpsTimer;

    //The frames per second cap timer
    SDLTimer capTimer;

    //In memory text stream
    std::stringstream timeText;

    //Start counting frames per second
    int countedFrames = 0;
    fpsTimer.start();




    bool stop=false;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:  // press X
                stop=true;
                Singleton::getInstance()->setCloseGame(true);
                break;

            case SDLK_ESCAPE:
                stop = true;
                ///Spel eindigen


                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym ){
                    case SDLK_UP:
                        //playerAddSpeed=true;
                        playerGoUp = true;

                        break;
                    case SDLK_DOWN:
                        // playerRemoveSpeed=true;
                        playerGoDown= true;
                        break;
                    case SDLK_LEFT:
                        playerLeft=true;

                        break;
                    case SDLK_RIGHT:
                        playerRight= true;
                        break;
                    case SDLK_SPACE:
                        shootRocket(true,player->getMPosX(),player->getMPosY(),0);
                        break;

                    case SDLK_RETURN:
                        printf("Enter pressed");
                        Singleton::getInstance()->setMenu(false);
                        break;

                    default:
                        break;

                }


                break;


            case SDL_KEYUP:
                switch (event.key.keysym.sym ){
                    case SDLK_UP:
                        //playerAddSpeed=false;
                        playerGoUp=false;
                        break;
                    case SDLK_DOWN:
                        // playerRemoveSpeed=false;
                        playerGoDown=false;
                        break;
                    case SDLK_LEFT:
                        playerLeft=false;

                        break;
                    case SDLK_RIGHT:
                        playerRight= false;
                        break;
                    case SDLK_SPACE:



                        break;
                    default:
                        break;

                }

                break;






            default:
                break;
        }
    }


    if(playerLeft){

    }




    //moest booleans gebruiken want ik kreeg een delay bij lange keypress dus boolean zetten bij elke keypress en aanpassen als er keyup of keydown is geregistreerd.
    player->goLeft(playerLeft);
    player->goRight(playerRight);
    player->addSpeed(playerAddSpeed);
    player->removeSpeed(playerRemoveSpeed);
    player->goUp(playerGoUp);
    player->goDown(playerGoDown);




    //Calculate and correct fps
    float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
    if( avgFPS > 2000000 )
    {
        avgFPS = 0;
    }

    //Update screen
    SDL_RenderPresent( gRenderer );
    ++countedFrames;

    //If frame finished early
    int frameTicks = capTimer.getTicks();
    if( frameTicks < SCREEN_TICKS_PER_FRAME )
    {
        //Wait remaining time
        SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
    }

    if(STOPGAME){
        stop=true;  //als close() is opgeroepen dan stoppen we met spelen
        STOPGAME=false;
    }
    return stop;
}







