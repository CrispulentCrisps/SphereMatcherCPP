#include "Scene.h"

void Scene::AddObject(int ID, float X, float Y, int W, int H, SDL_Renderer* rend, const char* FilePath, bool Static)
{
	Object * newobj = new Object(ID, X, Y, W, H, rend, FilePath, Static);
	Object_Count++;
	objects.push_back(newobj);
}

void Scene::AddUI(const char* font, int x, int y, int size, int type, int w, int h, int xpad, int ypad, int destination, SDL_Colour colour, SDL_Colour textcolour, SDL_Renderer* rend, const char* text)
{
	GUI* gui = new GUI();
	gui->Font = TTF_OpenFont(font, size);
	gui->text = text;
	if (gui->Font == NULL)
	{
		std::cout << "\n UI FONT NOT LOADED: " << SDL_GetError();
	}
	else
	{
		gui->textcol = textcolour;
		gui->surf = TTF_RenderText_Solid(gui->Font, text, gui->textcol);

		gui->tex = SDL_CreateTextureFromSurface(rend, gui->surf);

		SDL_FreeSurface(gui->surf);

		gui->R = colour.r;
		gui->G = colour.g;
		gui->B = colour.b;
		gui->S_R = gui->R / 2;
		gui->S_G = gui->G / 2;
		gui->S_B = gui->B / 2;

		gui->rec = new SDL_Rect;
		gui->Width = w;
		gui->Height = h;
		gui->rec->x = x;
		gui->rec->y = y;
		gui->rec->w = gui->Width;
		gui->rec->h = gui->Height;
		gui->UIType = type;
		ui.push_back(gui);
	}
	GUI_Count++;
}
