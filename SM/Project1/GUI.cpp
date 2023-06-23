#include "GUI.h"

void GUI::ChangeText(const char* text)
{

}

bool GUI::Hover()
{
	if (SDL_GetMouseState(0,0))
	{

	}
	else
	{
		return false;
	}
}

bool GUI::Clicked()
{
	return false;
}

void GUI::UpdateButton()
{
}
