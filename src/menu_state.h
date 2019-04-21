#ifndef MENU_STATE_INCLUDED
#define MENU_STATE_INCLUDED

#include "game_state.h"
#include "playing_state.h"


class MenuState : public GameState
{
    private:
    SDL_Surface* background;

    public:
    MenuState(Game* g);
    ~MenuState();
    void handleEvents();
    void draw();

};

#endif // MENU_STATE_INCLUDED
