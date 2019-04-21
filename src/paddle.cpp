#include "paddle.h"

Paddle::Paddle(Game* g, int x_, int y_)
{
    surface = loadImage("img/paddle.bmp");
    game = g;
    rect.x = x_;
    rect.y = y_;
    rect.w = WIDTH;
    rect.h = HEIGHT;
    velocity = 0;
}

void Paddle::update()
{
    //  Handle wall collision
    rect.y += velocity;
    if (rect.y < 0)
    {
        rect.y = 0;
    } else if (rect.y + HEIGHT > game->SCREEN_HEIGHT)
    {
        rect.y = game->SCREEN_HEIGHT - HEIGHT;
    }
}

