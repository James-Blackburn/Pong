#include "menu_state.h"
#include "game.h"

MenuState::MenuState(Game* g)
{
    background = loadImage("img/pong.bmp");
    game = g;
}

MenuState::~MenuState()
{
    SDL_FreeSurface(background);
}

void MenuState::draw()
{
    SDL_FillRect(game->getWindow(), nullptr, 0);
    blitToSurface(0, 0, background, game->getWindow());
}

void MenuState::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            game->setPlaying(false);
        } else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                game->switchState(new PlayingState(game));
            }
        }
    }
}
