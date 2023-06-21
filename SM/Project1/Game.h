#pragma once
#include <stdio.h>
#include <math.h>
#include <stack>
#include "Scene.h"
#include "resource.h"
#include "AudioSystem.h"

class Game
{
	//Variables
public:
	const char* GAME_FONT = "./res/font/Gepestev-nRJgO.ttf";

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

