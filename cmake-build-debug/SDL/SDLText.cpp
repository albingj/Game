//
// Created by bini on 19-May-19.
//

#include "SDLText.h"


SDLText:: SDLText(){

};

SDLText::~SDLText() {
    free();
}



void SDLText::free(){
    //Free texture if it exists
    if( text != NULL )
    {
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(text);
        text = NULL;
        font = NULL;
        TTF_CloseFont(font);
    }
}


void SDLText::renderHealth( int health) {

    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font == NULL) {
        printf("font error");
    }

    std::string score_text = "health: " + std::to_string(health);
    SDL_Color textColor = {255, 255, 255, 0};
    textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
    text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 120;  //controls the rect's x coordinate
    Message_rect.y = 5; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);
    TTF_CloseFont(font);

}


void SDLText::renderItem( int rockets){

    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font==NULL){
        printf("font error");
    }

    std::string score_text = "Rockets: " + std::to_string(rockets);
    SDL_Color textColor = { 255, 255, 255, 0 };
    textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
    text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 5;  //controls the rect's x coordinate
    Message_rect.y = 15; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);


}

void SDLText::renderScore( int score){
    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font==NULL){
        printf("font error");
    }

    std::string score_text = "Your score: " + std::to_string(score);
    SDL_Color textColor = { 255, 255, 255, 0 };
    textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
    text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 5;  //controls the rect's x coordinate
    Message_rect.y = 30; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);


}


void SDLText::renderTopScore( int score){
    font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 80);
    if (font==NULL){
        printf("font error");
    }

    std::string score_text = ""
                             "Your Top Score is\n"
                             "" + std::to_string(score);
    SDL_Color textColor = { 255, 255, 255, 0 };
    textSurface = TTF_RenderText_Blended_Wrapped(font, score_text.c_str(), textColor,1000);
    text = SDL_CreateTextureFromSurface(gRenderer, textSurface);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 50;  //controls the rect's x coordinate
    Message_rect.y = 600; // controls the rect's y coordinte
    Message_rect.w = 600; // controls the width of the rect
    Message_rect.h = 70; // controls the height of the rect

    SDL_RenderCopy(gRenderer, text, NULL, &Message_rect);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);


}