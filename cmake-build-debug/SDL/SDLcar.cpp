//
// Created by admin on 11/03/2019.
//

#include <iostream>
#include "SDLcar.h"
#include "LTexture.h"
#include "../../Game.h"
#include "../../Singleton.h"

SDLcar::SDLcar() {

    texture = new LTexture();

    SDLcar::ResetCar();

}


void SDLcar::LoadImage() {

    std::string car[9] = {
            "Audi.png",
            "Ambulance.png",
            "Black_viper.png",
            "Car.png"
            , "Mini_truck.png"
            , "Mini_van.png"
            , "Police.png"
            , "taxi.png"
            , "truck.png"
    };
    texture->loadFromFile("image/cars/"+ car[(rand() % 9)]);
    setWidth(texture->getWidth());
    setHeight(texture->getHeight());
}

void SDLcar::Visualize()
{

    texture->render( getMPosX() , getMPosY());
    //texture->renderDebug(getMPosX() , getMPosY());



}

void SDLcar::Free(){
    texture->free();
}

