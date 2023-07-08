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
        printf("\nFUCK: CANNOT LOAD TEXTURE");
        printf(s);
    }
    return texture;
}

Object::Object(int ID, float X, float Y, int w, int h, SDL_Renderer* rend, const char* FilePath, bool Static)
{
    ID = ID;
    SetPosition(X, Y);
    SetVelocity(0, 0);
    imgpath = FilePath;
    tex = IMG_LoadTexture(rend, imgpath);
    H = h;
    W = w;
    rect = new SDL_Rect;
    rect->x = X;
    rect->y = Y;
    rect->w = W;
    rect->h = H;

    if (rect != NULL)
    {
        std::cout << "RECT LOADED";
    }
    else
    {
        std::cout << SDL_GetError();
    }
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

void Object::UpdateObject()
{
    if (!Static)
    {
        X += XVel;
        Y += YVel;

        rect->x = X;
        rect->y = Y;
    }
}
