//
// Created by bini on 06-May-19.
//

#ifndef GAME_SDLDROPEDITEM_H
#define GAME_SDLDROPEDITEM_H


#include "../../DropedItem.h"
#include "LTexture.h"

class SDLDropedItem : public DropedItem {
    LTexture* texture;


public:
    SDLDropedItem();
    void Visualize();
    void LoadImage();
    void Free();
};


#endif //GAME_SDLDROPEDITEM_H
