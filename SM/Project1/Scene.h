#pragma once
#include "Object.h"
#include <vector>

class Scene
{
public:
	std::vector<Object> objects;
	void AddObject(int ID, float X, float Y, int W, int H, SDL_Renderer* rend, const char* FilePath);
};