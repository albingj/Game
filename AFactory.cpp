//
// Created by admin on 11/03/2019.
//

#include "AFactory.h"
#include "Singleton.h"


AFactory::AFactory(){

    player->setHealth(20);
    player->setRockets(10);
    STOPGAME = false;

}

AFactory::~AFactory() {

    //Free loaded images

    background->Free();
    player->Free();
    cars->Free();
    dropedItem->Free();

    delete background;
    delete menu;
    delete cars;
    delete dropedItem;
    delete player;


}

void AFactory::Reset() {
    player->Reset();

}
void AFactory::LoadBackground(){
    menu->LoadImage();
    background->LoadImage();
}
void AFactory::LoadMenu(){
    //Singleton::getInstance()->setScore(player->getScore());
    menu->Visualize();
}
void AFactory::CreatePlayer(){
    player->LoadImage();

}
void AFactory::CreateCars(){
    for(int i = 0 ; i < sizeof(cars); i++) {

        cars[i].LoadImage();

    }
}
void AFactory::CreateItems() {

    for(int i = 0 ; i < sizeof(dropedItem); i++) {
        dropedItem[i].reset();  //randomize item and relocate above to be reused.
    }

}
void AFactory::Draw() {

    //Render background texture to screen

    background->Visualize();


    for(int i =0 ; i < 4; i++){

        if(cars[i].getMPosY() > Singleton::getInstance()->getScreenBottom()){

            cars[i].ResetCar();
        }else if(cars[i].getMPosY() > -1000){
            cars[i].Visualize();

        }

    }

    for(int i =0 ; i < sizeof(dropedItem); i++){
        if(dropedItem[i].getMPosY() > Singleton::getInstance()->getScreenBottom()){
            dropedItem[i].reset();
        }else if(dropedItem[i].getMPosY() > -1000 && dropedItem[i].getType()<4 ){ // als type groter dan 3 is niets doen
            dropedItem[i].Visualize();
        }

    }



    for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {

        if ( (*it)->getMPosY() < Singleton::getInstance()->getScreenTop() || (*it)->getMPosY() > Singleton::getInstance()->getScreenBottom()){
            delete (*it);
            lstRocket.erase(it++);
        }else {
            (*it)->Visualize();
            ++it; //take next object
        }



    }


    player->Visualize();



}
void AFactory::Update(){
    //Update screen, alles op scherm tekenen.


    for(int i =0 ; i < 4; i++){
        cars[i].update();


        dropedItem[i].update();

        if (cars[i].getMPosY() > 20){
            shootRocket(false,cars[i].getMPosX(),cars[i].getMPosY(),i);

        }
    }



    //printf("listSize: %d\n", lstRocket.size());
    for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {
        (*it)->update();
        ++it; //take next object
    }


    if(player->getHealth()<1){
        //close();

        //save player score in singleton so we can use it on the menu screen because player stats will be erased when he dies.
        Singleton::getInstance()->setScore(player->getScore());
        STOPGAME = true;
        Singleton::getInstance()->setMenu(true);
    }

}
void AFactory::shootRocket(bool playerCar,int posX, int posY,int car){

    if (playerCar){
        if (player->getRockets()>0){
            player->setRockets(player->getRockets()-1);
            SDLRocket* toShoot = new SDLRocket();
            toShoot->setDirection(playerCar);
            toShoot->setVelocity(Singleton::getInstance()->getPlayerSpeed() + 7);
            toShoot->setMPosX(posX + 30);
            toShoot->setMPosY(posY);
            toShoot->LoadImage();
            lstRocket.push_back(toShoot);

        }

    }else{
        if (cars[car].getRockets()>0){
            cars[car].setRockets(cars[car].getRockets()-1);
            SDLRocket* toShoot = new SDLRocket();
            toShoot->setDirection(playerCar);
            toShoot->setVelocity(Singleton::getInstance()->getPlayerSpeed() + 5);
            toShoot->setMPosX(posX + 30);
            toShoot->setMPosY(posY + 200);
            toShoot->LoadImage();
            try {
                lstRocket.push_back(toShoot);
            }catch (const char *e) { printf((const char *) e); }




        }

    }

}
bool AFactory::checkCollision( int* collisionBoxA, int* collisionBoxB ) {

    //Colission idee van Lazyfoo
    // http://lazyfoo.net/SDL_tutorials/lesson17/index.php




//The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    //ik ga de collission box met 5% langs elke zijde verkleinen zodat je niet direct een collision hebt als je er juist tegen bent.
    leftA = collisionBoxA[0] + ((collisionBoxA[1] - collisionBoxA[3])*0,05 );
    rightA = collisionBoxA[0] + collisionBoxA[3] - ((collisionBoxA[1] - collisionBoxA[0])*0,5 );
    topA = collisionBoxA[1] + ((collisionBoxA[2]-collisionBoxA[1])* 0,05);
    bottomA = collisionBoxA[1] + collisionBoxA[2] - ((collisionBoxA[2]-collisionBoxA[1])* 0,05);

    //Calculate the sides of rect B
    leftB = collisionBoxB[0] + ((collisionBoxA[1] - collisionBoxA[3])*0,05 );
    rightB = collisionBoxB[0] + collisionBoxB[3] - ((collisionBoxA[1] - collisionBoxA[0])*0,5 );
    topB = collisionBoxB[1] + ((collisionBoxA[2]-collisionBoxA[1])* 0,05);
    bottomB = collisionBoxB[1] + collisionBoxB[2] - ((collisionBoxA[2]-collisionBoxA[1])* 0,05);


    delete[] collisionBoxA; //Delete uit heap
    delete[] collisionBoxB;


    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;



}
void AFactory::Collision() {

    //check if user has collision with droped item
    for(int i = 0 ; i < 4; i++) {
        if(checkCollision(dropedItem[i].getCollisionBox(),player->getCollisionBox())) {
            //printf("droped");
            switch (dropedItem[i].getType()) {
                /*
                * 0 = boost
                * 1 = health
                * 2 = rocket
                */
                case 0:
                    player->addSpeed(true);
                    player->setScore(1);
                    break;
                case 1:
                    player->setHealth(player->getHealth() + 10);
                    player->setScore(-3);
                    break;
                case 2:
                    player->setRockets(player->getRockets() + 20);
                    break;
                case 3:
                    player->removeSpeed(true);
                    player->setScore(-1) ;
                    break;
            }
            dropedItem[i].reset();

        }


    }

//check if user has collision with cars

    for(int i = 0 ; i < 4; i++) {

        if (checkCollision(cars[i].getCollisionBox(),player->getCollisionBox())){
            cars[i].ResetCar();
            player->setHealth(player->getHealth()-3);
            player->setScore(-3);
        }

        //check if the rockets collisions with user or car
        for(std::list<SDLRocket*>::iterator it = lstRocket.begin(); it != lstRocket.end();) {

            //check if player fired
            if((*it)->isDirection()){
                if (checkCollision(cars[i].getCollisionBox(),(*it)->getCollisionBox())){
                    cars[i].ResetCar();
                    delete (*it);
                    lstRocket.erase(it++);
                    player->setScore(2);

                }else{
                    ++it; //take next object
                }
            }else{

                if (checkCollision(player->getCollisionBox(), (*it)->getCollisionBox())) {
                    player->setHealth(player->getHealth() - 1);
                    delete (*it);
                    lstRocket.erase(it++);
                    player->setScore(-1);
                } else {
                    ++it; //take next object
                }

            }
        }





    }



    for(std::list<SDLRocket*>::iterator itPlayer = lstRocket.begin(); itPlayer != lstRocket.end();) {

        //check if player fired
        if ((*itPlayer)->isDirection()) { //if fired by player then check for collision with enemy rocket

            for(std::list<SDLRocket*>::iterator itCar = lstRocket.begin(); itCar != lstRocket.end();) {

                //check if car fired
                if(!(*itCar)->isDirection()){ //if fired by car (enemy) continue // False = car and True is from player
                    if(checkCollision((*itPlayer)->getCollisionBox(),(*itCar)->getCollisionBox())){
                        delete (*itPlayer);
                        lstRocket.erase(itPlayer++);
                        delete (*itCar);
                        lstRocket.erase(itCar++);
                        break;
                    }else{

                        ++itCar;
                    }
                }else{
                    ++itCar;
                }

            }

            ++itPlayer;

        }else {
            ++itPlayer;
        }

    }


}
