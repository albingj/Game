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
#include "SDLMenu.h"


//Using SDL and standard IO

//#include <stdio.h>
#include <string>
#include <iostream>

//Scene textures
SDLBackground* background = new SDLBackground();
SDLMenu* menu = new SDLMenu();

//Create 10 enemies
//SDLcar* car = new SDLcar();
SDLcar* cars = new SDLcar[4];
SDLDropedItem* dropedItem = new SDLDropedItem[4];
int EndScore;


//Car** cars = new Car[9];

SDLPlayer* player = new SDLPlayer();

SDL_Renderer* gRenderer = NULL;




//Frames maximum
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;



SDLFactory::SDLFactory() {
player->setHealth(20);
player->setRockets(10);
STOPGAME = false;

}
void SDLFactory::Reset() {

    player->Reset();

}


void SDLFactory::CreateSDLWindow() {
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
    menu->LoadImage();
    background->LoadImage();
    std::cout << ">>>>>> loadImageFromFile Background - done <<<<<<" << std::endl;
}
void SDLFactory::LoadMenu(){


    //Singleton::getInstance()->setScore(player->getScore());
    menu->Visualize();



}

void SDLFactory::CreatePlayer(){
   player->LoadImage();


    std::cout << ">>>>>> loadImageFromFile car - done <<<<<<" << std::endl;
}
void SDLFactory::CreateCars(){
    for(int i = 0 ; i < sizeof(cars); i++) {

        cars[i].LoadImage();

    }
}
void SDLFactory::CreateItems() {

    for(int i = 0 ; i < sizeof(dropedItem); i++) {
        dropedItem[i].reset();  //randomize item and relocate above to be reused.
     }

}
void SDLFactory::close()
{
    //Free loaded images

    background->Free();
    player->Free();
    cars->Free();
    dropedItem->Free();

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

    for(int i =0 ; i < sizeof(dropedItem); i++){
        if(dropedItem[i].getMPosY() > Singleton::getInstance()->getScreenBottom()){
            dropedItem[i].reset();
        }else if(dropedItem[i].getMPosY() > -1000 && dropedItem[i].getType()<4 ){ // als type groter dan 3 is niets doen
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

        //save player score in singleton so we can use it on the menu screen because player stats will be erased when he dies.
        Singleton::getInstance()->setScore(player->getScore());
        STOPGAME = true;
        Singleton::getInstance()->setMenu(true);
    }else{
        SDL_RenderPresent(gRenderer);
    }


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


bool checkCollision( int* collisionBoxA, int* collisionBoxB ) {

    //Colission idee van Lazyfoo
    // http://lazyfoo.net/SDL_tutorials/lesson17/index.php
    SDL_Rect A;
    SDL_Rect B;
    A.x = collisionBoxA[0];
    A.y = collisionBoxA[1];
    A.h = collisionBoxA[2];
    A.w = collisionBoxA[3];

    B.x = collisionBoxB[0];
    B.y = collisionBoxB[1];
    B.h = collisionBoxB[2];
    B.w = collisionBoxB[3];

    delete[] collisionBoxA; //Delete uit heap
    delete[] collisionBoxB;

//The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    //ik ga de collission box met 5% langs elke zijde verkleinen zodat je niet direct een collision hebt als je er juist tegen bent.
    leftA = A.x + ((A.y - A.w)*0,05 );
    rightA = A.x + A.w - ((A.y - A.x)*0,5 );
    topA = A.y + ((A.h-A.y)* 0,05);
    bottomA = A.y + A.h - ((A.h-A.y)* 0,05);

    //Calculate the sides of rect B
    leftB = B.x + ((A.y - A.w)*0,05 );
    rightB = B.x + B.w - ((A.y - A.x)*0,5 );
    topB = B.y + ((A.h-A.y)* 0,05);
    bottomB = B.y + B.h - ((A.h-A.y)* 0,05);
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;



 }

void SDLFactory::Collision() {

   //check if user has collision with droped item
    for(int i = 0 ; i < 4; i++) {
        if(checkCollision(dropedItem[i].getCollisionBox(),player->getCollisionBox())) {
            //printf("droped");
            switch (dropedItem[i].getType()) {
                /*
                * 0 = boost
                * 1 = health
                * 2 = rocket
                */
                case 0:
                    player->addSpeed(true);
                    player->setScore(1);
                    break;
                case 1:
                    player->setHealth(player->getHealth() + 10);
                    player->setScore(-3);
                    break;
                case 2:
                    player->setRockets(player->getRockets() + 20);
                    break;
                case 3:
                    player->removeSpeed(true);
                    player->setScore(-1) ;
                    break;
            }
            dropedItem[i].reset();

        }


    }

//check if user has collision with cars

    for(int i = 0 ; i < 4; i++) {

        if (checkCollision(cars[i].getCollisionBox(),player->getCollisionBox())){
           cars[i].ResetCar();
           player->setHealth(player->getHealth()-3);
            player->setScore(-3);
        }

        //check if the rockets collisions with user or car
        for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {

            //check if player fired
            if((*it)->isDirection()){
                if (checkCollision(cars[i].getCollisionBox(),(*it)->getCollisionBox())){
                    cars[i].ResetCar();
                    delete (*it);
                    lstRocket.erase(it++);
                    player->setScore(2);

                }else{
                    ++it; //take next object
                }
            }else{

                if (checkCollision(player->getCollisionBox(), (*it)->getCollisionBox())) {
                    player->setHealth(player->getHealth() - 1);
                    delete (*it);
                    lstRocket.erase(it++);
                    player->setScore(-1);
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



