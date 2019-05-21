//
// Created by bini on 19-May-19.
//

#include "SDLMenu.h"
#include "../../Singleton.h"


SDLMenu::SDLMenu() {
    texture = new LTexture();
    text = new SDLText();
}


void SDLMenu::LoadImage() {
    texture->loadFromFile("image/menu.png");
}

void SDLMenu::Visualize()
{

    texture->render( 0, 0 );
    text->renderTopScore( Singleton::getInstance()->getScore());



}
void SDLMenu::Free(){
    texture->free();
}