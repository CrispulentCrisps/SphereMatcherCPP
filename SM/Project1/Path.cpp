#include "Path.h"

void Path::AddBezier(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, int id)
{
	Bezier bez;
	bez.PA = p0;
	bez.PB = p1;
	bez.PC = p2;
	bez.PD = p3;
	bez.Bez_ID = id;
	Sections.push_back(bez);
}

Path::Vector2 Path::Evaluate(float t)
{
	//Control Point positions
	Vector2 AB;
	AB.x = lerp(Sections[0].PB.x, Sections[0].PA.x, (double)t);
	AB.y = lerp(Sections[0].PB.y, Sections[0].PA.y, (double)t);
	return AB;
}

void Path::UpdatePath(SDL_Renderer* rend)
{
	DEBUG_DrawPath(rend);
}

void Path::DEBUG_DrawPath(SDL_Renderer* rend)
{
	for (char j = 0; j < Sections.size(); j++)
	{
		for (char i = 0; i < StepSize; i++)
		{
			SDL_RenderDrawPoint(rend, Evaluate(i / StepSize).x, Evaluate(i / StepSize).y);
		}
	}
}
