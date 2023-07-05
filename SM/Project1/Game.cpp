#include "Game.h"

void Game::Update()
{
	while (Running)
	{
		FCount++;
		
		std::cout << FCount << "\n" << scenes.top().GUI_Count << "\n" << scenes.top().Object_Count << "\n";
	
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
		window = SDL_CreateWindow("SMC Version 0.0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_MOUSE_CAPTURE | SDL_WINDOW_INPUT_FOCUS);
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
			TTF_Init();
			sfxpath.push_back("./res/sfx/Jingle.wav");
			msxpath.push_back("./res/msx/Test.wav");
			as = new AudioSystem;
			as->LoadAudio(sfxpath,msxpath);
			as->ListAudio();
			as->InitSystem(1);
			//as->PlayAudio(0, false);
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
	SDL_GetMouseState(&MouseX, &MouseY);
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		End();
	}
}

void Game::Render(Scene curscene, SDL_Renderer* rend)
{
	SDL_RenderClear(rend);
	//Objects
	for (unsigned i = 0; i < curscene.objects.size(); i++)
	{
		curscene.objects[i]->UpdateObject();
		const SDL_Rect* rec = curscene.objects[i]->rect;
		SDL_RenderCopy(rend, curscene.objects[i]->tex, NULL, rec);
	}
	//UI
	for (unsigned i = 0; i < curscene.ui.size(); i++)
	{
		curscene.ui[i]->Update(MouseX, MouseY, e);
		curscene.ui[i]->GUI_Render(rend);
		const SDL_Rect* rec = curscene.ui[i]->rec;
		
		SDL_Colour blank = { 0, 0, 0 };
		SDL_SetRenderDrawColor(rend, blank.r, blank.g, blank.b, 0);
		SDL_RenderCopy(rend, curscene.ui[i]->tex, NULL, rec);
	}
	SDL_RenderPresent(rend);
}

void Game::CreateScenes()
{
	Scene TestScene;
	TestScene.AddObject(0, 64, 64,128 ,128 ,renderer, "./res/img/exp/TestBoi.png", true, 0);
	TestScene.AddObject(1, 64, 64,128 ,128 ,renderer, "./res/img/exp/Amonger.png", true, 0);
	SDL_Color col = { 128, 128, 128 };
	SDL_Color col2 = { 90, 90, 180 };
	SDL_Color col3 = { 128, 90, 180 };
	SDL_Colour coltex = { 255, 255, 255 };
	TestScene.AddUI(GAME_FONT, 240, 240, 128, 0, 256, 64, 8, 8, 0, col, coltex, renderer, "Engine time bay bee");
	TestScene.AddUI(GAME_FONT, 0, 304, 128, 1, 1920, 128, 8, 8, 0, col2, coltex, renderer, "God fucking dammit an amogus got in the fucking engine");
	TestScene.AddUI(GAME_FONT, 0, 428, 64, 2, 640, 128, 8, 8, 0, col3, coltex, renderer, "Please enter some text");
	TestScene.objects[0]->SetVelocity(.5, .25);
	TestScene.objects[1]->SetVelocity(.25, .125);
	scenes.push(TestScene);
}
