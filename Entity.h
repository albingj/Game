//
// Created by bini on 17-Apr-19.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


class Entity {



    //The X and Y offsets of the dot
    int mPosX=0, mPosY=0;



    //Elke entity moet onderstaande functies hebben!!!

    //moeten in het SDL gedeelte komen
    virtual void Visualize() = 0;
    virtual void LoadImage() = 0;
    virtual void Free()=0;


public:

    int getMPosX() const;
    void setMPosX(int mPosX);

    int getMPosY() const;
    void setMPosY(int mPosY);


};


#endif //GAME_ENTITY_H
