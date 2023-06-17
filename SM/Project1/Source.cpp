#include "Game.h"

int main(int argc, char* argv[]){
	SDL_SetMainReady();
	Game game;
	game.Start();
	game.Update();
	return 0;
}
