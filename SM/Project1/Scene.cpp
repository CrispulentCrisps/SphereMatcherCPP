#include "Scene.h"

void Scene::AddObject(int ID, float X, float Y, SDL_Renderer* rend, const char* FilePath)
{
	Object newobj = Object();
	newobj.ID = ID;
	newobj.SetPosition(X,Y);
	newobj.SetVelocity(0,0);
	newobj.imgpath = FilePath;
	newobj.IMG_LoadTexture(rend, newobj.imgpath);
}
