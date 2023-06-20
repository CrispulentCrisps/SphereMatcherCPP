#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

void Game::Update()
{
	int FCount = 0;
	while (Running)
	{
		FCount++;
		std::cout << FCount << "\n";
		
		Input();

		Render(scenes.top(), renderer);

		SDL_UpdateWindowSurface(window);

		SDL_Delay(1);
	}
}

void Game::Start()
{
	Running = true;
	window = NULL;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SMC", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screen = SDL_GetWindowSurface(window);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer != NULL)
			{
				printf("WORK");
			}
			else
			{
				const char* s = SDL_GetError();
				printf("FUCK\n");
				printf(s);
			}
			CreateScenes();
		}
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

void Game::Render(Scene curscene, SDL_Renderer* rend)
{
	for (unsigned i = 0; i < curscene.objects.size(); i++)
	{
		const SDL_Rect* rec = curscene.objects[i].rect;
		SDL_RenderCopy(rend, curscene.objects[i].tex, NULL, rec);
	}

	SDL_RenderPresent(rend);
}

void Game::CreateScenes()
{
	Scene TestScene;
	TestScene.objects.resize(5);
	TestScene.AddObject(0, 10, 10,128 ,128 ,renderer, "./res/img/exp/TestBoi.png");
	scenes.push(TestScene);
}
