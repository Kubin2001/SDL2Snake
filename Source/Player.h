#pragma once
#include <SDL.h>
#include <vector>
#include "Food.h"
class Segment {
	friend class Player;
	private:
		SDL_Rect rectangle;
	public:
		SDL_Rect* GetRectangle();
};

class Player {
	private:
		SDL_Texture* textures[5];
		SDL_Texture* segmenttex = nullptr;
		SDL_Rect rectangle{520,440,40,40};
		std::vector<Segment> segments;
		int MovementType = 1;
		int MovementBuffor = 0;
	public:
		void Movement();

		void AddSegment(Segment &segment);

		void Colision();

		void Center();

		SDL_Texture* GetTexture(int type);

		void SetTexture(SDL_Texture* temptex,int type);

		SDL_Rect* GetRectangle();

		void Render(SDL_Renderer* renderer);

		void Eat(Food *food);

		SDL_Texture* GetTextureSegment();

		void  SetTextureSegment(SDL_Texture* temptex);

};