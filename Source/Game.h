#pragma once
#include <SDL.h>
#include "Map.h"
#include "Player.h"
#include "Food.h"
class Game {
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture* mainTexture;

		Map* map;
		Player* player;
		Food* food;
		
	public:
		void StartGame();

		void LoadTextures();

		void Events();

		void Movement();

		void Render();

		SDL_Texture* load(const char* file, SDL_Renderer* ren);
};
