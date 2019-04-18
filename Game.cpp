//
// Created by admin on 11/03/2019.
//
#include <iostream>
#include <chrono>
#include <zconf.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include "Game.h"
#include "Car.h"
#include "Singleton.h"


Game::Game(AFactory *pFactory) {
    this->pFactory = pFactory;

    //Singleton* s = Singleton::getInstance(); // Ok

}

void Game::start(){

    std::cout << ">>>>>> Start <<<<<<" << std::endl;
    pFactory->CreateWindow();  //initialisatie van SDL


    //Create game objects
    //Car* car = pFactory->CreateCar();


    std::cout << ">>>>>> Create Background <<<<<<" << std::endl;
    pFactory->LoadBackground();
    pFactory->CreatePlayer();
    //car->vis();



    //zolang er niet op X gedrukt wordt in de loop blijven
    //Input update ook user input voor Player
    while(!pFactory->Input()) {

        //Handle events on queue



            //oude items weg doen van scherm
            pFactory->ClearScreen();

            //locaties van entities updaten
            pFactory->Draw();

            //alles tonen op scherm
            pFactory->Update();



        SDL_Delay(30);
    }



    std::cout << ">>>>>> END <<<<<<" << std::endl;



}
