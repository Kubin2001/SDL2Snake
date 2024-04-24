#pragma once
#include <SDL.h>
#include <ctime>
#include <cstdlib>

class Food {
private:
	SDL_Texture* texture = nullptr;
	SDL_Rect rectangle;
	int MaxValueX = 880 / 40;
	int MaxValueY = 680 / 40;
	int Rand = 0;
	int Rand2 = 0;
	int Countdown = 450;
public:

	SDL_Texture* GetTexture();

	void  SetTexture(SDL_Texture* temptex);

	SDL_Rect* GetRectangle();

	void Render(SDL_Renderer* renderer);

	void SetCountdown(int temp);

	void Spawn();
};