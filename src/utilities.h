#ifndef UTILITIES_INCLUDED
#define UTILITIES_INCLUDED
#include "SDL.h"

inline SDL_Surface* loadImage(const char* path)
{
    SDL_Surface* loadedImage = SDL_LoadBMP(path);
    SDL_Surface* optimisedImage = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);
    return optimisedImage;
}

inline void blitToSurface(int x, int y, SDL_Surface* source,
                    SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, nullptr, destination, &offset);
}

#endif // UTILITIES_INCLUDED
