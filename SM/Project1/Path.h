/*
* ///////////////////////////////////////////////////////////////////////
* / This class is for the path required for sphere movement and editing /
* ///////////////////////////////////////////////////////////////////////
*/

#pragma once
#include <cmath>
#include <vector>
#include "Knob.h"
#include "SDL_image.h"
#include "SDL.h"

using namespace std;

class Path
{
public:
	//variables
	bool Editing;
	int StepSize;
	//structs
	struct Vector2 
	{
		double x = 0;
		double y = 0;
	};
	
	struct Bezier
	{
		int Bez_ID;
		Vector2 PA, PB, PC, PD;
		//2 end points 2 control points
		Knob knobs[2][2];
	};

	std::vector<Bezier> Sections;

	//functions
	void AddBezier(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, int id);
	Vector2 Evaluate(float t);
	void UpdatePath(SDL_Renderer* rend);
	void DEBUG_DrawPath(SDL_Renderer* rend);
};

