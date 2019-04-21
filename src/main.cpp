#include <ctime>
#include <random>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "game.h"

Game game;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Init( SDL_INIT_VIDEO );
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    TTF_Init();
    game.initialize();

    while (game.isPlaying())
    {
        game.update();
        game.draw();
        game.handleEvents();
        SDL_Delay(17);
    }

    delete game.getCurrentState();
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
