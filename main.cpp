///Game has been made by following the following tutorial: http://lazyfoo.net/tutorials/SDL/index.php + some google searches :)
///And help from my teachers


#include <iostream>
#include "Game.h"
#include "cmake-build-debug/SDL/SDLFactory.h"

int main( int argc, char* args[]) {
    std::cout << ">>>>>> Program Started <<<<<<" << std::endl;

    AFactory* aFactory;
    aFactory = new SDLFactory();

    Game* game = new Game(aFactory);
    game->start();

    delete game;
    delete aFactory;


    return 0;
}

