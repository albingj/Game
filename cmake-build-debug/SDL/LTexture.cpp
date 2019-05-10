//
// Created by bini on 18/03/2019.
//

#include "LTexture.h"
#include "SDLFactory.h"
#include "../../Game.h"

#include <SDL2/SDL_ttf.h>


LTexture::LTexture(){

    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;

}

LTexture::~LTexture(){
    //Deallocate
    free();
}

bool LTexture::loadFromFile( std::string path){
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        //printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            //printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

void LTexture::free(){
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;


    }
}

void LTexture::render(int x, int y) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopy(gRenderer,mTexture,NULL,&renderQuad);
}

void LTexture::renderDebug(int x, int y) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_SetRenderDrawColor(gRenderer, 255 , 255 , 255, 255);
    SDL_RenderDrawRect(gRenderer, &renderQuad);

//SDL_RenderCopy(gRenderer,SDL_CreateColorCursor(255),NULL,&renderQuad);



}
void LTexture::renderHealth( int health) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {10, 10, 100, 10};
    SDL_SetRenderDrawColor(gRenderer, 255 , 255 , 255, 255);
    SDL_RenderDrawRect(gRenderer, &renderQuad);

    renderQuad = {10+1, 10+1, 100/20*health-2, 10-2};

    SDL_SetRenderDrawColor(gRenderer, 255 , 0 , 0, 0);
    SDL_RenderFillRect(gRenderer, &renderQuad);
    SDL_RenderDrawRect(gRenderer, &renderQuad);

//------------------------------------------------------------------

    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font==NULL){
        printf("font error");
    }

    std::string score_text = "health: " + std::to_string(health);
    SDL_Color textColor = { 255, 255, 255, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
    SDL_Texture* text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 120;  //controls the rect's x coordinate
    Message_rect.y = 5; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);
}
void LTexture::renderItem( int rockets){

    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font==NULL){
        printf("font error");
    }

    std::string score_text = "Rockets: " + std::to_string(rockets);
    SDL_Color textColor = { 255, 255, 255, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
    SDL_Texture* text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 5;  //controls the rect's x coordinate
    Message_rect.y = 15; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);


}

void LTexture::renderScore( int score){

    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font==NULL){
        printf("font error");
    }

    std::string score_text = "Your score: " + std::to_string(score);
    SDL_Color textColor = { 255, 255, 255, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
    SDL_Texture* text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 5;  //controls the rect's x coordinate
    Message_rect.y = 30; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);


}





int LTexture::getWidth(){
    return this->mWidth;
}

int LTexture::getHeight(){
    return this->mHeight;
}















