#include "GUI.h"

void GUI::ChangeText(const char* text)
{

	surf = TTF_RenderText_Solid(Font, text, textcol);

	tex = SDL_CreateTextureFromSurface(rend, gui->surf);

	SDL_FreeSurface(gui->surf);

	rec = new SDL_Rect;
	Width = w;
	Height = h;
	rec->x = x;
	rec->y = y;
	rec->w = Width;
	rec->h = Height;

}

bool GUI::Hover(int x, int y)
{
	if (x >= rec->x  && x <= rec->x + rec->w && y >= rec->y && y <= rec->y + rec->h)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GUI::Clicked(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == 0)
		{
			return true;
		}
	}
	return false;
}

void GUI::Update(int x, int y, SDL_Event e)	
	{
	if (UIType == 1)
	{
		Hovering = Hover(x, y);
		if (Hovering)
		{
			Clicked(e);
		}
	}
}

void GUI::GUI_Render(SDL_Renderer* rend)
{
	if (UIType == 1)
	{
		if (Hovering)
		{
			SDL_SetRenderDrawColor(rend, S_R, S_G, S_B, 0);
		}
		else
		{
			SDL_SetRenderDrawColor(rend, R, G, B, 0);
		}
	}
	else
	{
		SDL_SetRenderDrawColor(rend, R, G, B, 0);
	}
	SDL_RenderFillRect(rend, rec);
}
