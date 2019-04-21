#include "sprite.h"
#include "game.h"

Sprite::~Sprite()
{
    SDL_FreeSurface(surface);
}


void Sprite::draw()
{
    blitToSurface(rect.x, rect.y, surface, game->getWindow());
}

bool Sprite::checkCollision(SDL_Rect& otherRect)
{
    if( rect.y + rect.h <=  otherRect.y )
    {
        return false;
    }

    if( rect.y >= otherRect.y + otherRect.h )
    {
        return false;
    }

    if( rect.x + rect.w <= otherRect.x )
    {
        return false;
    }

    if( rect.x >= otherRect.x + otherRect.w )
    {
        return false;
    }

    return true;
}
