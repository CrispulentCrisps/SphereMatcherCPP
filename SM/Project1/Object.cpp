#include "Object.h"

SDL_Texture* Object::IMG_LoadTexture(SDL_Renderer* renderer, const char* file)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(file);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    else
    {
        const char* s = SDL_GetError();
        printf("FUCK\n");
        printf(s);
    }
    return texture;
}

void Object::SetPosition(float x, float y)
{
    X = x;
    Y = y;
}

void Object::SetVelocity(float xvel, float yvel)
{
    XVel = xvel;
    YVel = yvel;
}
