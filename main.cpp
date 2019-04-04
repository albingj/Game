#include <iostream>
#include "Game.h"
#include "SDLFactory.h"

int main( int argc, char* args[]) {
    std::cout << ">>>>>> Program Started <<<<<<" << std::endl;

    AFactory* aFactory;
    aFactory = new SDLFactory();

    Game* game = new Game(aFactory);
    game->start();


    return 0;
}