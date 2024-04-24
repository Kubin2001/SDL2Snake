#include <iostream>
#include <SDL.h>
#include "SDL_image.h"

#include "Food.h"

SDL_Texture* Food::GetTexture() {
	return texture;
}

void Food::SetTexture(SDL_Texture* temptex) {
	texture = temptex;
}

SDL_Rect* Food::GetRectangle() {
	return &rectangle;
}

void Food::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &rectangle);
}

void Food::SetCountdown(int temp) {
	Countdown = temp;
}

void Food::Spawn() {
	Countdown++;
	if (Countdown > 500) {
		Rand = std::rand() % MaxValueX * 40 + 40;
		Rand2 = std::rand() % MaxValueY * 40 + 40;
		rectangle.x = Rand;
		rectangle.y = Rand2;
		rectangle.w = 40;
		rectangle.h = 40;
		Countdown = 0;
	}
}