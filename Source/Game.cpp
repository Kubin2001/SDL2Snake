#include <SDL.h>
#include "SDL_image.h"

#include "Game.h"

void Game::StartGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    map = new Map();
    player = new Player();
    food = new Food();

    Segment segment;

    LoadTextures();

    player->AddSegment(segment);

}

void Game::LoadTextures() {
    map->SetTexture(load("textures/map.png", renderer));

    map->SetTextureWall(load("textures/wall.png", renderer));

    player->SetTexture(load("textures/player.png", renderer),1);
    player->SetTexture(load("textures/player2.png", renderer), 2);
    player->SetTexture(load("textures/player3.png", renderer), 3);
    player->SetTexture(load("textures/player4.png", renderer), 4);

    food->SetTexture(load("textures/food.png", renderer));

    player->SetTextureSegment(load("textures/segment.png", renderer));
}

void Game::Events() {
    food->Spawn();
    player->Eat(food);
    player->Colision();
}

void Game::Movement() {
    player->Movement();
}

void Game::Render() {;
    SDL_RenderClear(renderer);

    map->createMap(renderer);
    food->Render(renderer);
    player->Render(renderer);


    SDL_RenderPresent(renderer);

}

SDL_Texture* Game::load(const char* file, SDL_Renderer* ren) {
    SDL_Surface* tmpSurface = IMG_Load(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;

}