#pragma once
#include <SDL_ttf.h>

	class GUI
	{
	public:
		TTF_Font* Font;
		
		int UIType;
		int Width;
		int Height;
		int X;
		int Y;
		float XPadding;
		float YPadding;
		int Destination;
		bool Hovering;

		SDL_Colour textcol;

		Uint8 R;
		Uint8 G;
		Uint8 B;

		Uint8 S_R;
		Uint8 S_G;
		Uint8 S_B;

		SDL_Texture* tex;
		SDL_Rect* rec;
		SDL_Surface* surf;

		void ChangeText(const char* text);
		bool Hover(int x, int y);
		bool Clicked(SDL_Event e);
		void Update(int x, int y, SDL_Event e);
		void GUI_Render(SDL_Renderer* rend);
	};

