//
// Created by admin on 11/03/2019.
//
#include <iostream>
#include <chrono>
#include <zconf.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <fibersapi.h>
#include "Game.h"
#include "Car.h"
#include "Singleton.h"
using namespace std;
Game::Game(AFactory *pFactory) {
    this->pFactory = pFactory;

    //Singleton* s = Singleton::getInstance(); // Ok

}

void Game::start(){

    std::cout << ">>>>>> Start <<<<<<" << std::endl;
    pFactory->CreateSDLWindow();  //initialisatie van SDL







    std::cout << ">>>>>> Create Background <<<<<<" << std::endl;
    pFactory->LoadBackground();
    pFactory->CreatePlayer();
    pFactory->CreateCars();
    pFactory->CreateItems();










while (!Singleton::getInstance()->isCloseGame()) {

    //Input update ook user input voor Player
    while (!pFactory->Input()) {

        //Menu
        if (Singleton::getInstance()->isMenu()) {
            pFactory->LoadMenu();
        } else {


            //Handle events on queue

            //oude items weg doen van scherm
            pFactory->ClearScreen();

            //Check for collisions
            pFactory->Collision();

            //locaties van entities updaten
            pFactory->Draw();

            //alles tonen op scherm
            pFactory->Update();



            //SDL_Delay(30);
        }
    }
    pFactory->Reset();




}



    pFactory->close();
    std::cout << ">>>>>> END <<<<<<" << std::endl;






















}

