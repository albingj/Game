//
// Created by bini on 17-Apr-19.
//

#include "Player.h"
#include "Singleton.h"

Player::~Player() {
    setHealth(10);

}



void Player::addSpeed(bool key){
    if(key){
        if(getMVelY() < 101) {
            this->speed += getMVelY();
            Singleton::getInstance()->setPlayerSpeed(this->speed);

        }

        if(this->getMVelY() > 20) {
            //setMPosY(getMPosY()-1);
            Singleton::getInstance()->setPlayerSpeed(this->speed-getMVelY());

        }


    }
};
void Player::removeSpeed(bool key){
    if(key) {
        if(this->speed > 0){
            this->speed -= getMVelY();
            Singleton::getInstance()->setPlayerSpeed(this->speed);


        }




    }
}





void Player::goLeft(bool key) {
    if(key){
        if (getMPosX()>30) {
            setMPosX(getMPosX()-10);



        }
    }
}

void Player::goRight(bool key) {
    if(key) {
        if (getMPosX()+getWidth()<550) {

            setMPosX(getMPosX()+10);



        }
    }
}
void Player::SetReaction(int reaction){

    setMVelX(reaction);

}

void Player::shoot(bool b){



}