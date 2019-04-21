#include "game_state.h"
#include "game.h"

void GameState::update(){}

void GameState::draw()
{
    SDL_FillRect(game->getWindow(), nullptr, SDL_MapRGB(game->getWindow()->format, 0, 0, 0));
}

void GameState::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            game->setPlaying(false);
        }
    }
}


