//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


class Entity {


    //Elke entity moet onderstaande functies hebben!!!
    virtual void Visualize() = 0;
    virtual void LoadImage() = 0;
    virtual void Free()=0;

    virtual void setPosX(int x) = 0;
    virtual void setPosY(int y) = 0;

    //virtual void SetSpeed(int velocity) = 0;


};


#endif //GAME_ENTITY_H
