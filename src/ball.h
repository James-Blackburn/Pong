#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "game.h"
#include "sprite.h"
#include "utilities.h"

class Ball : public Sprite
{
    private:
    int xVelocity, yVelocity;

    public:

    static const int WIDTH = 16;
    static const int HEIGHT = 16;
    static const int SPEED = 8;

    Ball(Game* g, int x_, int y_);
    void update();

    inline void setVelocity(int xVal, int yVal)
    {
        xVelocity = xVal;
        yVelocity = yVal;
    }

    inline int getVelocityX()
    {
        return xVelocity;
    }

    inline int getVelocityY()
    {
        return yVelocity;
    }
};

#endif // BALL_H_INCLUDED
