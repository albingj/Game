//
// Created by admin on 11/03/2019.
//
#include <string>
#include <sstream>
#include "SDLFactory.h"
#include "SDLcar.h"
#include "../../Game.h"
#include "SDLBackground.h"
#include "SDLPlayer.h"
#include "../../Singleton.h"
#include "../SDL/SDLTimer.h"


//Using SDL and standard IO

//#include <stdio.h>
#include <string>
#include <iostream>

//Scene textures
SDLBackground* background = new SDLBackground();


//Create 10 enemies
//SDLcar* car = new SDLcar();
SDLcar* cars = new SDLcar[9];

SDLPlayer* player = new SDLPlayer();

SDL_Renderer* gRenderer = NULL;


//keypress booleans
bool playerLeft=false,playerRight=false,playerAddSpeed=false,playerRemoveSpeed=false;


//Frames maximum
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;



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
        //printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );

    }
    else
    {
        std::cout << ">>>>>> SDL init - no error" << std::endl;
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
                std::cout << ">>>>>> SDL init - Create renderer for window" << std::endl;
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
                    std::cout << ">>>>>> SDL init - Initialize renderer color" << std::endl;
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


    for(int i =0 ; i < 4; i++){

        if(cars[i].getCollisionBox().y > Singleton::getInstance()->getScreenBottom()){
            //std::cout << ">>>>>> SDL FREE car" << std::endl;
            cars[i].ResetCar();
        }else if(cars[i].getCollisionBox().y > -1000){
            cars[i].Visualize();
        }else{

        }


    }


    player->Visualize();



}


void SDLFactory::Update(){
    //Update screen, alles op scherm tekenen.
    SDL_RenderPresent(gRenderer);
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
                break;

            case SDLK_ESCAPE:
                stop = true;
                ///Spel eindigen


                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym ){
                    case SDLK_UP:
                        playerAddSpeed=true;
                        break;
                    case SDLK_DOWN:
                        playerRemoveSpeed=true;
                        break;
                    case SDLK_LEFT:
                        playerLeft=true;

                        break;
                    case SDLK_RIGHT:
                        playerRight= true;
                        break;
                    case SDLK_SPACE:

                        break;
                    default:
                        break;

                }


                break;


            case SDL_KEYUP:
                switch (event.key.keysym.sym ){
                    case SDLK_UP:
                        playerAddSpeed=false;
                        break;
                    case SDLK_DOWN:
                        playerRemoveSpeed=false;
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

    std::ostringstream oss;
    //oss << "player x:" << player->getX() << " y:" << player->getY() << " speed:" << Singleton::getInstance()->getPlayerSpeed();
    //std::cout << oss.str() << std::endl;




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


    return stop;
}




void SDLFactory::CreateCars(){



    for(int i = 0 ; i < 4; i++) {

        //cars[i].SetSpeed(-2);
        cars[i].LoadImage();

    }






}



bool checkCollision(SDL_Rect objectA, SDL_Rect objectB ) {

    /*

     elke object heeft 4 hoeken
     a - b
     |   |
     c - d

     Als een andere object zijn hoekpunt in de andere komt wordt dit beschoud als een botsing

     */

//The sides of the rectangles


    if (
            //objectB.y < objectA.y && objectB.y > objectA.x+objectA.h




            //check of object B zijn lengte langs de Yas objectA overlapt
            ( objectB.y <= objectA.y+objectA.h && objectB.y >= objectA.y  //By tussen Ay+h en Ay  ??
             || objectB.y +objectB.h <= objectA.y+objectA.h && objectB.y +objectB.h >= objectA.y) &&  // By+h tussen Ay+h en Ay ??





             (objectB.x <= objectA.x+objectA.w && objectB.x >= objectA.x
             ||(objectB.x+objectB.w) <= objectA.x+objectA.w && objectB.x+objectB.w >= objectA.x)



            ){
        printf("true\n");
        return true;
    }



    return false;
}

void SDLFactory::Collision() {

   // if (CheckCollision)

    printf("Ax: %d | Ax+h: %d | Bx: %d\n",cars[0].getCollisionBox().x,cars[0].getCollisionBox().x+cars[0].getCollisionBox().w,player->getCollisionBox().x+player->getCollisionBox().w);
    //checkCollision(cars[0].getCollisionBox(),player->getCollisionBox());



    for(int i = 0 ; i < 9; i++) {

        //cars[i].ResetCar();




        if (checkCollision(cars[i].getCollisionBox(),player->getCollisionBox())){
           cars[i].ResetCar();
        }


    }




}



