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

	Uint8 R;
	Uint8 G;
	Uint8 B;

	SDL_Texture* tex;
	SDL_Rect* rec;
	SDL_Surface* surf;
};

