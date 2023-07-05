#pragma once
#include "Object.h"
#include "GUI.h"
#include <vector>

class Scene
{
public:
	std::vector<Object * > objects;
	std::vector<GUI * > ui;

	int GUI_Count = 0;
	int Object_Count = 0;

	void AddObject(int ID, float X, float Y, int W, int H, SDL_Renderer* rend, const char* FilePath, bool Static, int ObjectType);
	void AddUI(const char* font, int x, int y, int size, int type, int w, int h, int xpad, int ypad, int destination, SDL_Colour colour, SDL_Colour textcolour, SDL_Renderer* rend, const char* text);
};