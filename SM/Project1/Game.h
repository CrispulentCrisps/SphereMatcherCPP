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
	const char* OS = SDL_GetPlatform();
	//Screen dimensions
	int SCREEN_WIDTH = 1920;
	int SCREEN_HEIGHT = 1080;
	int MouseX;
	int MouseY;
	SDL_Event e;

	bool Running;
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Renderer* renderer;
	Scene AvailableScenes[1];
	std::stack<Scene> scenes;
	AudioSystem* as;
	vector<string> sfxpath;
	vector<string> msxpath;
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

