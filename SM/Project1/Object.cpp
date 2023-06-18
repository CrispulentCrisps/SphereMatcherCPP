#include "Object.h"

SDL_Texture* IMG_LoadTexture(SDL_Renderer* renderer, const char* file)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(file);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
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