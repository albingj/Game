//
// Created by bini on 17-Apr-19.
//

#include <SDL2/SDL_events.h>
#include "SDLinput.h"



void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                //exit(0);
                break;

            default:
                break;
        }
    }
}