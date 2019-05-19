//
// Created by bini on 19-May-19.
//

#include "SDLMenu.h"


SDLMenu::SDLMenu() {
    texture = new LTexture();

}


void SDLMenu::LoadImage() {
    texture->loadFromFile("image/menu.png");
}

void SDLMenu::Visualize()
{

    texture->render( 0, 0 );

}
void SDLMenu::Free(){
    texture->free();
}