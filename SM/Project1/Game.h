#pragma once
#include <stdio.h>
#include <math.h>
#include <stack>
#include "Scene.h"
#include "resource.h"

class Game
{
	//Variables
public:
	const int GUI_STANDBY = 90 + 90 + 180;
	const int GUI_ACTIVE = 45 + 45 + 90;
	
	bool Running;
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Renderer* renderer;
	Scene AvailableScenes[1];
	std::stack<Scene> scenes;
	//Structs
	

	//Functions
public:
	void Update();
	void Start();
	void End();
	void Input();
	void Render(Scene curscene, SDL_Renderer* rend);
	void CreateScenes();
};

