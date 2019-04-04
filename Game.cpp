//
// Created by admin on 11/03/2019.
//
#include <iostream>
#include <chrono>
#include <zconf.h>
#include <SDL2/SDL_events.h>
#include "Game.h"
#include "Car.h"



Game::Game(AFactory *pFactory) {
    this->pFactory = pFactory;
}

void Game::start(){
bool stop = false;

    std::cout << ">>>>>> Start <<<<<<" << std::endl;
    pFactory->CreateWindow();

    //Create game objects
    Car* car = pFactory->CreateCar();


    std::cout << ">>>>>> Create Background <<<<<<" << std::endl;
    pFactory->CreateBackground();
    //car->vis();




    SDL_Event e;


    while(!stop) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                stop = true;


            }
            pFactory->Draw();
            car->vis();
            pFactory->Update();
            //usleep(500);
        }



    }



    std::cout << ">>>>>> END <<<<<<" << std::endl;



}