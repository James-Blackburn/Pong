#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "SDL/SDL.h"
#include <vector>

#include "game_state.h"
#include "menu_state.h"
#include "playing_state.h"
#include "utilities.h"



class Game
{
    private:

    SDL_Surface* window = nullptr;
    GameState* currentState = nullptr;
    bool playing = true;

    public:

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;

    void initialize();
    void draw();
    void update();
    void handleEvents();
    void switchState(GameState* state);
    inline bool isPlaying() { return playing; }
    inline void setPlaying(bool val) { playing = val; }
    inline SDL_Surface* getWindow() { return window; }
    inline GameState* getCurrentState() { return currentState; }
};

#endif // GAME_H_INCLUDED
