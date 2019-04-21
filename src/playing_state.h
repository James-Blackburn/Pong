#ifndef PLAYING_STATE_INCLUDED
#define PLAYING_STATE_INCLUDED

class Game;
class Paddle;
class Ball;

#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "game_state.h"
#include "paddle.h"
#include "ball.h"
#include "game.h"

#include <vector>
#include <string>

class PlayingState : public GameState
{
    private:
    Paddle* leftPaddle = nullptr;
    Paddle* rightPaddle = nullptr;
    Ball* ball = nullptr;
    SDL_Surface* score = nullptr;
    SDL_Surface* line = nullptr;
    Mix_Chunk* blip = nullptr;

    bool switchState = false;

    int player1Score;
    int player2Score;

    void newBall(int side);
    void updateScore(const std::string& message);
    void loadFiles();

    public:

    PlayingState(Game *g);
    ~PlayingState();
    void draw();
    void update();
    void handleEvents();
};

#endif // PLAYING_STATE_INCLUDED
