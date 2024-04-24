#include <SDL.h>
#include "SDL_image.h"

#include "Map.h"

SDL_Texture* Map::GetTexture() {
	return texture;
}

void Map::SetTexture(SDL_Texture * temptex) {
	texture = temptex;
}

SDL_Texture* Map::GetTextureWall() {
	return texturewall;
}

void Map::SetTextureWall(SDL_Texture* temptex) {
	texturewall = temptex;
}

SDL_Rect *Map::GetRectangle() {
	return &rectangle;
}

void Map::createMap(SDL_Renderer *renderer) {
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			rectangle.x += 40;
			if (i == 0 || i == 19 || j == 0 || j == 24) {
				SDL_RenderCopy(renderer, texturewall, NULL, &rectangle);
			}
			else
			{
				SDL_RenderCopy(renderer, texture, NULL, &rectangle);
			}
			
			
		}
		rectangle.x = -40;
		rectangle.y += 40;
	}
	rectangle.y = 0;

}