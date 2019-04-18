//
// Created by bini on 18-Apr-19.
//

#ifndef GAME_SDLTIMER_H
#define GAME_SDLTIMER_H


#include <SDL2/SDL_stdinc.h>

class SDLTimer {
public:
    //Initializes variables
    SDLTimer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};


#endif //GAME_SDLTIMER_H
