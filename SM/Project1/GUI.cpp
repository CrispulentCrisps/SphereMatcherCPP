#include "GUI.h"

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
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			return true;
		}
	}
	return false;
}

void GUI::Update(int x, int y, SDL_Event e)	
{
	switch (UIType)
	{
	default:
		break;
		// Button
	case 1:
		Hovering = Hover(x, y);
		if (Hovering)
		{
			MouseDown = Clicked(e);
		}
		break;
	case 2: //Text Input
		Hovering = Hover(x, y);
		if (Hovering)
		{
			MouseDown = Clicked(e);
			if (MouseDown)
			{
				Focused = true;
			}
		}
		else if (Clicked(e)) 
		{
			Focused = false;
			text = ghosttext;
		}
		if (Focused)
		{
			if (e.key.keysym.scancode != SDL_SCANCODE_BACKSPACE)
			{
				if (e.type == SDL_TEXTINPUT)
				{
					inputtext += e.text.text;
				}
			}
			else
			{
				if (inputtext.length() > 0)
				{
					inputtext.pop_back();
				}
			}
		}
		break;
	}
}

void GUI::GUI_Render(SDL_Renderer* rend)
{
	SDL_DestroyTexture(tex);
	SDL_Colour col;
	col = textcol;
	switch (UIType)
	{
	default:
		col = textcol;
		SDL_SetRenderDrawColor(rend, R, G, B, 0);
		break;
	case 1:
		if (Hovering)
		{
			SDL_SetRenderDrawColor(rend, S_R, S_G, S_B, 0);
		}
		else
		{
			SDL_SetRenderDrawColor(rend, R, G, B, 0);
		}
		col = textcol;
		break;
	case 2:
		if (Hovering)
		{
			SDL_SetRenderDrawColor(rend, S_R, S_G, S_B, 0);
		}
		else
		{
			SDL_SetRenderDrawColor(rend, R, G, B, 0);
		}
		if (Focused)
		{
			col = textcol;
		}
		else if (inputtext == "")
		{
			col = ghostcol;
		}
		break;
	}

	SDL_RenderFillRect(rend, rec);
	
	if (UIType == 2 && inputtext != "")
	{
		surf = TTF_RenderText_Solid(Font, inputtext.data(), col);
	}
	else
	{
		surf = TTF_RenderText_Solid(Font, text.data(), col);
	}

	tex = SDL_CreateTextureFromSurface(rend, surf);

	SDL_FreeSurface(surf);	
}
