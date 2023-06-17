#pragma once
#include <stdio.h>
#include <math.h>
#include <stack>
#include "Scene.h"

class Game
{
	//Variables
public:
	bool Running;
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Renderer* renderer;
	std::stack<Scene> scenes;
	//Structs

	//Functions
public:
	void Update();
	void Start();
	void End();
	void Input();
	void Render();
	void CreateScenes();
};

