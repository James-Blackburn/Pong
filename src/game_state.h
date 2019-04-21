#ifndef GAME_STATE_INCLUDED
#define GAME_STATE_INCLUDED

class Game;

#include <vector>

#include "SDL/SDL.h"
#include "utilities.h"


class GameState
{
    protected:
        Game* game = nullptr;

    public:
        virtual void update();
        virtual void draw();
        virtual void handleEvents();

};

#endif // GAME_STATE_INCLUDED
