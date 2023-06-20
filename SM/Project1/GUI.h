#pragma once
#include <SDL_ttf.h>

class GUI
{
public:
	TTF_Font* Font;
	int UIType;
	int Width;
	int Height;
	float XPadding;
	float YPadding;
	int Destination;

	SDL_Texture* tex;
	SDL_Rect* rec;
	SDL_Surface* surf;
};

