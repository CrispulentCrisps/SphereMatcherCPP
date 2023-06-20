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

		SDL_Delay(17);
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
				printf("RENDERER WORKING \n");
			}
			else
			{
				const char* s = SDL_GetError();
				printf("RENDERER FUCKED \n");
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
	SDL_DestroyRenderer(renderer);
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
	SDL_RenderClear(rend);
	for (unsigned i = 0; i < curscene.objects.size(); i++)
	{
		curscene.objects[i]->UpdateObject();
		const SDL_Rect* rec = curscene.objects[i]->rect;
		SDL_RenderCopy(rend, curscene.objects[i]->tex, NULL, rec);
	}

	for (unsigned i = 0; i < curscene.ui.size(); i++)
	{
		SDL_FillRect(curscene.ui[i]->surf, curscene.ui[i]->rec, GUI_STANDBY);
		const SDL_Rect* rec = curscene.ui[i]->rec;
		SDL_RenderCopy(rend, curscene.ui[i]->tex, NULL, rec);
	}

	SDL_RenderPresent(rend);
}

void Game::CreateScenes()
{
	Scene TestScene;
	Scene TestScene2;
	TestScene.AddObject(0, 64, 64,128 ,128 ,renderer, "./res/img/exp/TestBoi.png", true, 0);
	TestScene2.AddObject(1, 16, 16,64 ,64 ,renderer, "./res/img/exp/TestBoi.png", false, 0);
	SDL_Colour* col;
	col = SDL_MapRGB(0, 255, 255, 255);
	TestScene2.AddUI("./res/font/Gepestev-nRJgO.ttf", 690, 360, 24, 0, 24, 24, 8, 8, 0, , , renderer, "!This is some test text!");
	TestScene2.objects[0]->SetVelocity(1, 1);
	scenes.push(TestScene);
	scenes.push(TestScene2);
}
