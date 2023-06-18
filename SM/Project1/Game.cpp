#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

void Game::Update()
{
	while (Running)
	{
		screen = SDL_GetWindowSurface(window);

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

		Input();

		Render(scenes.top());

		SDL_UpdateWindowSurface(window);
	
	}
}

void Game::Start()
{
	Running = true;
	window = NULL;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SMC", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screen = SDL_GetWindowSurface(window);
		}

		CreateScenes();
	}

}

void Game::End()
{
	Running = false;
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::Input()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		End();
	}
}

void Game::Render(Scene curscene)
{
	SDL_FreeSurface(screen);
	SDL_RenderClear(renderer); //clears the renderer
	for (unsigned i = 0; i < curscene.objects.size(); i++)
	{
		//SDL_RenderCopy(renderer,curscene.objects , NULL, &);
	}
	

	SDL_RenderPresent(renderer);
}

void Game::CreateScenes()
{
	Scene* TestScene = new Scene();
	TestScene->objects.resize(5);
	TestScene->AddObject(0, 0, 0,128 ,128 ,renderer, "/res/img/exp/TestBoi.png");
}
