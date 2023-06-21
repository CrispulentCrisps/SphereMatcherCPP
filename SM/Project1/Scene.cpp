#include "Scene.h"

void Scene::AddObject(int ID, float X, float Y, int W, int H, SDL_Renderer* rend, const char* FilePath, bool Static, int ObjectType)
{
	Object * newobj = new Object();
	newobj->ID = ID;
	newobj->SetPosition(X,Y);
	newobj->SetVelocity(0,0);
	newobj->imgpath = FilePath;
	newobj->tex = newobj->IMG_LoadTexture(rend, newobj->imgpath);
	newobj->H = H;
	newobj->W = W;
	newobj->rect = new SDL_Rect;
	newobj->rect->x = X;
	newobj->rect->y = Y;
	newobj->rect->w = newobj->W;
	newobj->rect->h = newobj->H;

	if (newobj->rect != NULL)
	{
		std::cout << "RECT LOADED";
	}
	else
	{

		std::cout << SDL_GetError();
	}

	objects.push_back(newobj);
}

void Scene::AddUI(const char* font, int x, int y, int size, int type, int w, int h, int xpad, int ypad, int destination, SDL_Colour colour, SDL_Colour textcolour, SDL_Renderer* rend, const char* text)
{
	GUI* gui = new GUI();
	TTF_Font* F = TTF_OpenFont(font, size);

	if (F == NULL)
	{
		std::cout << "\n UI FONT NOT LOADED: " << SDL_GetError();
	}
	else
	{
		gui->surf = TTF_RenderText_Solid(F, text, textcolour);

		gui->tex = SDL_CreateTextureFromSurface(rend, gui->surf);

		gui->R = colour.r;
		gui->G = colour.g;
		gui->B = colour.b;

		gui->rec = new SDL_Rect;
		gui->Width = w;
		gui->Height = h;
		gui->rec->x = x - (((sizeof(text) / 8) * size) - xpad);
		gui->rec->y = y - (((sizeof(text) / 8) * size) - ypad);
		gui->rec->w = gui->Width;
		gui->rec->h = gui->Height;
		ui.push_back(gui);
	}
}
