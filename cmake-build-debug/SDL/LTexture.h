//
// Created by bini on 18/03/2019.
//

#ifndef GAME_LTEXTURE_H
#define GAME_LTEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <string>



//Screen dimension constants
const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 650;



//texture wrapper class
class LTexture{
private:

public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path );

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(int x, int y);
    void renderDebug(int x, int y);
    void renderHealth(int health);
    void renderItem(int rockets);
    void renderScore(int score);
    //Gets image dimensions
    int getWidth();
    int getHeight();

    void Draw();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;




    //Image dimensions
    int mWidth;
    int mHeight;
    //Globally used font




};


#endif //GAME_LTEXTURE_H
