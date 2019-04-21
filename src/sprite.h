#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

class Game;

#include "SDL/SDL.h"
#include "utilities.h"


class Sprite
{
    protected:
    Game* game;
    SDL_Surface* surface = nullptr;
    int velocity;

    public:

    static const int WIDTH = 0;
    static const int HEIGHT = 0;
    SDL_Rect rect;

    virtual ~Sprite();
    virtual void draw();
    virtual bool checkCollision(SDL_Rect& otherRect);
    virtual inline void setVelocity(int val) { velocity = val; }
};

#endif // SPRITE_H_INCLUDED
