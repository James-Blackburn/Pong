#include "ball.h"

Ball::Ball(Game* g, int x_, int y_)
{
    surface = loadImage("img/ball.bmp");
    game = g;
    rect.x = x_;
    rect.y = y_;
    rect.w = WIDTH;
    rect.h = HEIGHT;
}

void Ball::update()
{
    rect.x += xVelocity;
    rect.y += yVelocity;
}
