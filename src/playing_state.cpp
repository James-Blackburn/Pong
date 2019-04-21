#include "playing_state.h"

PlayingState::PlayingState(Game* g)
{
    game = g;
    player1Score = 0;
    player2Score = 0;
    loadFiles();
    newBall(0);
}

PlayingState::~PlayingState()
{
    delete leftPaddle;
    delete rightPaddle;
    delete ball;
    SDL_FreeSurface(score);
    SDL_FreeSurface(line);
    Mix_FreeChunk(blip);
}

void PlayingState::loadFiles()
{
    leftPaddle = new Paddle(game, 0, game->SCREEN_HEIGHT/2 - Paddle::HEIGHT/2);
    rightPaddle = new Paddle(game, game->SCREEN_WIDTH - Paddle::WIDTH,
            game->SCREEN_HEIGHT/2 - Paddle::HEIGHT/2);
    line = loadImage("img/line.bmp");
    blip = Mix_LoadWAV_RW(SDL_RWFromFile("snd/blip.wav", "rb"), 1);
    updateScore(std::to_string(player1Score)+"   "+std::to_string(player2Score));
}

void PlayingState::updateScore(const std::string& message)
{
    SDL_FreeSurface(score);
    TTF_Font* font = TTF_OpenFont( "fnt/font.ttf", 28 );
    SDL_Color textColor = { 255, 255, 255 };
    const char* c = message.c_str();
    SDL_Surface* renderedFont = TTF_RenderText_Solid(font, c, textColor);
    score = SDL_DisplayFormat( renderedFont );
    SDL_FreeSurface(renderedFont);
}

void PlayingState::newBall(int side)
{
    delete ball;
    ball = new Ball(game, game->SCREEN_WIDTH/2 - Ball::WIDTH/2,
            game->SCREEN_HEIGHT/2 - Ball::HEIGHT/2);
    switch (side)
    {
        case 1:
            ball->setVelocity(-Ball::SPEED, 0);
        break;

        case 2:
            ball->setVelocity(Ball::SPEED, 0);
        break;

        default:
            if (rand()%2)
            {
                ball->setVelocity(Ball::SPEED, 0);
            } else
            {
                ball->setVelocity(-Ball::SPEED, 0);
            }
        break;
    }
}

void PlayingState::draw()
{
    SDL_FillRect(game->getWindow(), nullptr, 0);
    blitToSurface(game->SCREEN_WIDTH/2 - 10, 0, line, game->getWindow());
    leftPaddle->draw();
    rightPaddle->draw();
    ball->draw();
    blitToSurface(game->SCREEN_WIDTH/2 - 75, 0, score, game->getWindow());
}

void PlayingState::update()
{
    // Ball collision with wall
    if (ball->rect.x < 0 || ball->rect.x > game->SCREEN_WIDTH)
    {
        if (ball->rect.x < game->SCREEN_WIDTH/2)
        {
            player2Score++;
            newBall(2);
        } else
        {
            player1Score++;
            newBall(1);
        }
        if (player1Score >= 10)
        {
            updateScore("player 1 wins");
            switchState = true;
        } else if (player2Score >= 10)
        {
            updateScore("player 2 wins");
            switchState = true;
        } else
        {
            updateScore(std::to_string(player1Score)+"   "+std::to_string(player2Score));
        }
    }

    // Bounce ball on wall
    if (ball->rect.y <= 0 || ball->rect.y + ball->rect.h >= game->SCREEN_HEIGHT)
    {
        ball->setVelocity(ball->getVelocityX(), -ball->getVelocityY());
    }

    // Ball collision with paddles
    if (ball->checkCollision(leftPaddle->rect))
    {
        Mix_PlayChannel(-1, blip, 0);
        ball->setVelocity(-ball->getVelocityX(), -ball->getVelocityY()/2 + leftPaddle->getVelocity());
    } else if (ball->checkCollision(rightPaddle->rect))
    {
        Mix_PlayChannel(-1, blip, 0);
        ball->setVelocity(-ball->getVelocityX(), -ball->getVelocityY()/2 + rightPaddle->getVelocity());
    }

    leftPaddle->update();
    rightPaddle->update();
    ball->update();
}

void PlayingState::handleEvents()
{
    SDL_Event event;
    while ( SDL_PollEvent(&event) )
    {
        if (event.type == SDL_QUIT)
        {
            game->setPlaying(false);
        } else if ( event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_w)
            {
                leftPaddle->setVelocity(-Paddle::SPEED);
            } else if (event.key.keysym.sym == SDLK_s)
            {
                leftPaddle->setVelocity(Paddle::SPEED);
            } if (event.key.keysym.sym == SDLK_UP)
            {
                rightPaddle->setVelocity(-Paddle::SPEED);
            } else if (event.key.keysym.sym == SDLK_DOWN)
            {
                rightPaddle->setVelocity(Paddle::SPEED);
            }
        } else if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_s)
            {
                leftPaddle->setVelocity(0);
            } if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN)
            {
                rightPaddle->setVelocity(0);
            }
        }
    }
    if (switchState)
    {
        SDL_Delay(1000);
        game->switchState(new PlayingState(game));
    }
}
