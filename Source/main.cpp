#include <iostream>
#include <SDL.h>
#include <ctime>
#include <cstdlib>

#include "Game.h"

int main(int argv,char * argc[])
{
	std::srand(std::time(0));
	bool status = true;
	Game* game = new Game();
	
	game->StartGame();

	while (status)
	{
		game->Movement();
		game->Events();
		game->Render();
		
		SDL_Delay(16);
	}

	delete game;

	return 0;

}
