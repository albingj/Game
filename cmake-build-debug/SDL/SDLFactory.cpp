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
#include "SDLRocket.h"
#include "SDLDropedItem.h"


//Using SDL and standard IO

//#include <stdio.h>
#include <string>
#include <iostream>

//Scene textures
SDLBackground* background = new SDLBackground();


//Create 10 enemies
//SDLcar* car = new SDLcar();
SDLcar* cars = new SDLcar[4];
SDLDropedItem* dropedItem = new SDLDropedItem[4];



//Car** cars = new Car[9];

SDLPlayer* player = new SDLPlayer();

SDL_Renderer* gRenderer = NULL;




//Frames maximum
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;



SDLFactory::SDLFactory() {
player->setHealth(20);
player->setRockets(10);

}

void SDLFactory::CreateWindow() {
    init();
}

void SDLFactory::init(){

    std::cout << ">>>>>> SDL init() <<<<<<" << std::endl;
    TTF_Init();
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
void SDLFactory::CreateCars(){
    for(int i = 0 ; i < 4; i++) {

        cars[i].LoadImage();

    }
}
void SDLFactory::CreateItems() {

    for(int i = 0 ; i < 4; i++) {
        dropedItem[i].reset();  //randomize item and relocate above to be reused.
     }

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

    TTF_Quit();
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

        if(cars[i].getMPosY() > Singleton::getInstance()->getScreenBottom()){

            cars[i].ResetCar();
        }else if(cars[i].getMPosY() > -1000){
            cars[i].Visualize();

        }

    }

    for(int i =0 ; i < 4; i++){
        if(dropedItem[i].getMPosY() > Singleton::getInstance()->getScreenBottom()){
            dropedItem[i].reset();
        }else if(dropedItem[i].getMPosY() > -1000 && dropedItem[i].getType()<4 && dropedItem->getType()<3){ // als type groter dan 3 is niets doen
            dropedItem[i].Visualize();
        }

    }



    for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {

    if ( (*it)->getMPosY() < Singleton::getInstance()->getScreenTop() || (*it)->getMPosY() > Singleton::getInstance()->getScreenBottom()){
            delete (*it);
            lstRocket.erase(it++);
        }else {
            (*it)->Visualize();
            ++it; //take next object
        }



    }






    player->Visualize();



}


void SDLFactory::Update(){
    //Update screen, alles op scherm tekenen.


    for(int i =0 ; i < 4; i++){
        cars[i].update();


        dropedItem[i].update();

        if (cars[i].getMPosY() > 20){
            shootRocket(false,cars[i].getMPosX(),cars[i].getMPosY(),i);

        }
    }



    //printf("listSize: %d\n", lstRocket.size());
    for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {
        (*it)->update();
        ++it; //take next object
    }


    if(player->getHealth()<1){
        //close();
    }

    SDL_RenderPresent(gRenderer);
}


void SDLFactory::shootRocket(bool playerCar,int posX, int posY,int car){

    if (playerCar){
        if (player->getRockets()>0){
            player->setRockets(player->getRockets()-1);
            SDLRocket* toShoot = new SDLRocket();
            toShoot->setDirection(playerCar);
            toShoot->setVelocity(Singleton::getInstance()->getPlayerSpeed() + 7);
            toShoot->setMPosX(posX + 30);
            toShoot->setMPosY(posY);
            toShoot->LoadImage();
            lstRocket.push_back(toShoot);

        }

    }else{
        if (cars[car].getRockets()>0){
            cars[car].setRockets(cars[car].getRockets()-1);
            SDLRocket* toShoot = new SDLRocket();
            toShoot->setDirection(playerCar);
            toShoot->setVelocity(Singleton::getInstance()->getPlayerSpeed() + 5);
            toShoot->setMPosX(posX + 30);
            toShoot->setMPosY(posY + 200);
            toShoot->LoadImage();
            try {
                lstRocket.push_back(toShoot);
            }catch (const char *e) { printf((const char *) e); }




        }

    }

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








bool checkCollision( int* collisionBoxA, int* collisionBoxB ) {



    SDL_Rect objectA;
    SDL_Rect objectB;



    objectA.x = collisionBoxA[0];
    objectA.y = collisionBoxA[1];
    objectA.h = collisionBoxA[2];
    objectA.w = collisionBoxA[3];

    objectB.x = collisionBoxB[0];
    objectB.y = collisionBoxB[1];
    objectB.h = collisionBoxB[2];
    objectB.w = collisionBoxB[3];

    delete[] collisionBoxA; //Delete uit heap
    delete[] collisionBoxB;


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
            ( objectB.y < objectA.y+objectA.h && objectB.y > objectA.y  //By tussen Ay+h en Ay  ??
             || objectB.y +objectB.h < objectA.y+objectA.h && objectB.y +objectB.h > objectA.y)


             &&  // By+h tussen Ay+h en Ay ??


             (objectB.x < objectA.x+objectA.w && objectB.x > objectA.x
             ||(objectB.x+objectB.w) < objectA.x+objectA.w && objectB.x+objectB.w > objectA.x)



            ){
        //printf("true\n");
        return true;
    }


   // printf("false\n");
    return false;
 }

void SDLFactory::Collision() {


    for(int i = 0 ; i < 4; i++) {
        if(checkCollision(dropedItem[i].getCollisionBox(),player->getCollisionBox())) {
            printf("droped");
            switch (dropedItem[i].getType()) {
                /*
                * 0 = boost
                * 1 = health
                * 2 = rocket
                */
                case 0:
                    player->addSpeed(true);
                    break;
                case 1:
                    player->setHealth(player->getHealth() + 10);
                    break;
                case 2:
                    player->setRockets(player->getRockets() + 20);
                    break;
            }
            dropedItem[i].reset();

        }


    }


    for(int i = 0 ; i < 4; i++) {

        if (checkCollision(cars[i].getCollisionBox(),player->getCollisionBox())){
           cars[i].ResetCar();
           player->setHealth(player->getHealth()-3);
        }

        for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {

            //check if player fired
            if((*it)->isDirection()){
                if (checkCollision(cars[i].getCollisionBox(),(*it)->getCollisionBox())){
                    cars[i].ResetCar();
                    delete (*it);
                    lstRocket.erase(it++);
                    player->setScore(5);

                }else{
                    ++it; //take next object
                }
            }else{

                if (checkCollision(player->getCollisionBox(), (*it)->getCollisionBox())) {
                    player->setHealth(player->getHealth() - 1);
                    delete (*it);
                    lstRocket.erase(it++);
                } else {
                    ++it; //take next object
                }

            }
        }





    }



    for(std::list<SDLRocket*>::iterator itPlayer = lstRocket.begin(); itPlayer != lstRocket.end();) {

        //check if player fired
        if ((*itPlayer)->isDirection()) { //if fired by player then check for collision with enemy rocket

                for(std::list<SDLRocket*>::iterator itCar = lstRocket.begin(); itCar != lstRocket.end();) {

                    //check if car fired
                    if(!(*itCar)->isDirection()){ //if fired by car (enemy) continue // False = car and True is from player
                        if(checkCollision((*itPlayer)->getCollisionBox(),(*itCar)->getCollisionBox())){
                            delete (*itPlayer);
                            lstRocket.erase(itPlayer++);
                            delete (*itCar);
                            lstRocket.erase(itCar++);
                            break;
                        }else{

                            ++itCar;
                        }
                    }else{
                        ++itCar;
                    }

                }

            ++itPlayer;

        }else {
            ++itPlayer;
        }

    }


}



