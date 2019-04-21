#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

#include "game.h"
#include "sprite.h"
#include "utilities.h"

class Paddle : public Sprite
{
    public:

    static const int WIDTH = 16;
    static const int HEIGHT = 96;
    static const int SPEED = 8;

    Paddle(Game* g, int x_, int y_);
    void update();

    inline void setVelocity(int val)
    {
        velocity = val;
    }

    inline int getVelocity()
    {
        return velocity;
    }
};

#endif // PADDLE_H_INCLUDED
