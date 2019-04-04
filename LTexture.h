//
// Created by bini on 18/03/2019.
//

#ifndef GAME_LTEXTURE_H
#define GAME_LTEXTURE_H
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

#include <string>



//Screen dimension constants
const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 650;



//Texture wrapper class
class LTexture{
private:
    SDL_Renderer* sdlRenderer = nullptr;
public:
    //Initializes variables
    LTexture(SDL_Renderer* sdlRenderer);

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path );

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(int x, int y, SDL_Renderer *pRenderer);

    //Gets image dimensions
    int getWidth();
    int getHeight();

    void Draw();

private:
    //The actual hardware texture
    SDL_Texture* mTexture = nullptr;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //GAME_LTEXTURE_H
