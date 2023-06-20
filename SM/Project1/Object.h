#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
class Object
{
public:
	bool Static;
	int ID;
	float X;
	float Y;
	float XVel;
	float YVel;
	int W;
	int H;

	const char* imgpath;
	SDL_Texture* IMG_LoadTexture(SDL_Renderer* renderer, const char* file);
	SDL_Rect* rect;
	SDL_Texture* tex;

	
	void SetPosition(float x, float y);
	void SetVelocity(float xvel, float yvel);
	void UpdateObject();
};

