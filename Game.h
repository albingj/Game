//
// Created by admin on 11/03/2019.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H


#include "AFactory.h"

class Game {
    AFactory *pFactory = nullptr;


public:
    Game(AFactory *pFactory);

    void start();
};



#endif //GAME_GAME_H
