#include "Scene.h"

void Scene::AddObject(int ID, float X, float Y, int W, int H, SDL_Renderer* rend, const char* FilePath)
{
	Object newobj = Object();
	newobj.ID = ID;
	newobj.SetPosition(X,Y);
	newobj.SetVelocity(0,0);
	newobj.imgpath = FilePath;
	newobj.tex = newobj.IMG_LoadTexture(rend, newobj.imgpath);
	newobj.H = H;
	newobj.W = W;
	newobj.rect = new SDL_Rect;
	newobj.rect->x = X;
	newobj.rect->y = Y;
	newobj.rect->w = newobj.W;
	newobj.rect->h = newobj.H;

	objects.push_back(newobj);
}
