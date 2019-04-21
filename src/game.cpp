#include "game.h"

void Game::initialize()
{
    window = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT,
                                SCREEN_BPP, SDL_SWSURFACE);
    SDL_WM_SetCaption("Pong", nullptr);
    currentState = new MenuState(this);
}

void Game::draw()
{
    currentState->draw();
    SDL_Flip( window );
}

void Game::update()
{
    currentState->update();
}

void Game::handleEvents()
{
    currentState->handleEvents();
}

void Game::switchState(GameState* state)
{
    delete currentState;
    currentState = state;
}
