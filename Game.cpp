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



Game::Game(AFactory *pFactory) {
    this->pFactory = pFactory;
}

void Game::start(){

    bool stop = false;

    std::cout << ">>>>>> Start <<<<<<" << std::endl;
    pFactory->CreateWindow();  //initialisatie van SDL


    //Create game objects
    //Car* car = pFactory->CreateCar();


    std::cout << ">>>>>> Create Background <<<<<<" << std::endl;
    pFactory->LoadBackground();
    pFactory->CreatePlayer();
    //car->vis();




    SDL_Event e;


    while(!stop) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                stop = true;


            }

            //oude items weg doen van scherm
            pFactory->ClearScreen();

            //locaties van entities updaten
            pFactory->Draw();

            //alles tonen op scherm
            pFactory->Update();

        }


        SDL_Delay(30);
    }



    std::cout << ">>>>>> END <<<<<<" << std::endl;



}
