//
// Created by admin on 11/03/2019.
//


#ifndef GAME_AFACTORY_H
#define GAME_AFACTORY_H
#include "cmake-build-debug/SDL/SDLBackground.h"
#include "cmake-build-debug/SDL/SDLMenu.h"
#include "cmake-build-debug/SDL/SDLPlayer.h"
#include "cmake-build-debug/SDL/SDLDropedItem.h"

#include <SDL2/SDL_render.h>


class AFactory {

    //Scene textures
    SDLBackground* background = new SDLBackground();
    SDLMenu* menu = new SDLMenu();

//Create 10 enemies
//SDLcar* car = new SDLcar();
    SDLcar* cars = new SDLcar[4];
    SDLDropedItem* dropedItem = new SDLDropedItem[4];
    int EndScore;


//Car** cars = new Car[9];



    std::list<SDLRocket*> lstRocket;


public:

    SDLPlayer* player = new SDLPlayer();
    bool STOPGAME;

    AFactory();
    ~AFactory();
   // AFactory();
   bool checkCollision( int*, int*);
   //virtual Car* CreateCar() =0;

   void Reset();

     void LoadBackground();
     void LoadMenu();
     void CreatePlayer();

     void CreateCars();
     void Collision();
     void Update();
     void Draw();
    void CreateItems();
    void shootRocket(bool playerCar, int posX, int posY, int car);

    virtual bool Input()=0;
    virtual void CreateSDLWindow()=0;
    virtual void close()=0;
    virtual void ClearScreen()=0;

};

#endif //GAME_AFACTORY_H