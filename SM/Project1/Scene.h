#pragma once
#include "Object.h"
#include <list>

class Scene
{
public:
	std::list<Object> objects;
	void AddObject(int ID, float X, float Y, SDL_Renderer* rend, const char* FilePath);
};