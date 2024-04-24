#pragma once
#include <SDL.h>
class Map {

	private:
		SDL_Texture* texture = nullptr;
		SDL_Texture* texturewall = nullptr;
		SDL_Rect rectangle{ 0,0,40,40 };

	public:
		
		SDL_Texture* GetTexture();

		void  SetTexture(SDL_Texture* temptex);

		SDL_Texture* GetTextureWall();

		void  SetTextureWall(SDL_Texture* temptex);

		SDL_Rect *GetRectangle();

		void createMap(SDL_Renderer* renderer);
};	