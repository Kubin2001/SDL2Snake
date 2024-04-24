#include <SDL.h>
#include "SDL_image.h"
#include <iostream>

#include "Player.h"
#include "Food.h"

void Player::Movement() {
    MovementBuffor++;
    SDL_PumpEvents();
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_UP]) {
        if (MovementType != 2) {
            MovementType = 1;
        }
        
    }
    else if (state[SDL_SCANCODE_DOWN]) {
        if (MovementType != 1) {
            MovementType = 2;
        }
    }
    else if (state[SDL_SCANCODE_LEFT]) {
        if(MovementType != 4) {
            MovementType = 3;
        }
    }
    else if (state[SDL_SCANCODE_RIGHT]) {
        if (MovementType != 3) {
            MovementType = 4;
        }
    }

    if (MovementBuffor > 20) {
        MovementBuffor = 0;

        for (int i = segments.size() - 1; i > 0; i--) {
            segments[i].GetRectangle()->x = segments[i - 1].GetRectangle()->x;
            segments[i].GetRectangle()->y = segments[i - 1].GetRectangle()->y;
        }

        if (!segments.empty()) {
            segments[0].GetRectangle()->x = rectangle.x;
            segments[0].GetRectangle()->y = rectangle.y;
        }

        switch (MovementType) {
            case 1:
                rectangle.y -= 40;
                break;
            case 2:
                rectangle.y += 40;
                break;
            case 3:
                rectangle.x -= 40;
                break;
            case 4:
                rectangle.x += 40;
                break;
        }
    }
}


void Player::AddSegment(Segment &segment) {
    
    switch (MovementType) {
        case 1:
            segments.push_back(segment);
            segments[segments.size() - 1].GetRectangle()->y = GetRectangle()->y + 40;
            segments[segments.size() - 1].GetRectangle()->x = GetRectangle()->x;
            break;
        case 2:
            segments.push_back(segment);
            segments[segments.size() - 1].GetRectangle()->y = GetRectangle()->y - 40;
            segments[segments.size() - 1].GetRectangle()->x = GetRectangle()->x;
            break;
        case 3:
            segments.push_back(segment);
            segments[segments.size() -1].GetRectangle()->x = GetRectangle()->x + 40;
            segments[segments.size() -1].GetRectangle()->y = GetRectangle()->y;
            break;
        case 4:
            segments.push_back(segment);
            segments[segments.size() - 1].GetRectangle()->x = GetRectangle()->x - 40;
            segments[segments.size() - 1].GetRectangle()->y = GetRectangle()->y;
            break;
    }
    segments[segments.size() - 1].GetRectangle()->w = GetRectangle()->w;
    segments[segments.size() - 1].GetRectangle()->h = GetRectangle()->h;
}

void Player::Colision() {
    if (MovementBuffor == 0) {
        Segment segment;
        for (int i = 0; i < segments.size(); i++)
        {
            if (segments[i].GetRectangle()->x == GetRectangle()->x && segments[i].GetRectangle()->y == GetRectangle()->y) {
                segments.clear();
                Center();
                
                AddSegment(segment);
            }
        }
        if (GetRectangle()->x < 40 || GetRectangle()->x > 920 || GetRectangle()->y < 40 || GetRectangle()->y > 720) {
            segments.clear();
            Center();
            AddSegment(segment);
        }
        
    }

}

void Player::Center() {
    GetRectangle()->x = 520;
    GetRectangle()->y = 440;
    MovementType = 1;
}

SDL_Texture* Player::GetTexture(int type) {
    switch (type) {
        case 1:
            return textures[0];
            break;
        case 2:
            return textures[1];
            break;
        case 3:
            return textures[2];
            break;
        case 4:
            return textures[3];
            break;
        case 5:
            return textures[4];
            break;
    }
	
}

void Player::SetTexture(SDL_Texture* temptex,int type) {
	
    switch (type) {
    case 1:
        textures[0] = temptex;
        break;
    case 2:
        textures[1] = temptex;
        break;
    case 3:
        textures[2] = temptex;
        break;
    case 4:
        textures[3] = temptex;
        break;
    case 5:
        textures[4] = temptex;
        break;
    }

}

SDL_Rect* Player::GetRectangle() {
	return &rectangle;
}

void Player::Render(SDL_Renderer* renderer) {
    if (segments.size() > 0) {
        for (int i = 0; i < segments.size(); i++)
        {
            SDL_RenderCopy(renderer, segmenttex, NULL, segments[i].GetRectangle());
        }
    }
    switch (MovementType) {
    case 1:
        SDL_RenderCopy(renderer, textures[0], NULL, &rectangle);
        break;
    case 2:
        SDL_RenderCopy(renderer, textures[2], NULL, &rectangle);
        break;
    case 3:
        SDL_RenderCopy(renderer, textures[3], NULL, &rectangle);
        break;
    case 4:
        SDL_RenderCopy(renderer, textures[1], NULL, &rectangle);
        break;
    }
    
    
}

void Player::Eat(Food *food) {
    Segment segment;
    if (rectangle.x == food->GetRectangle()->x && rectangle.y == food->GetRectangle()->y) {
        food->SetCountdown(500);
        //std::cout << "Hihi\n";
        AddSegment(segment);
    }
    
}
//Segments//////////////////////////

SDL_Rect* Segment::GetRectangle() {
    return &rectangle;
}

SDL_Texture* Player::GetTextureSegment() {
    return segmenttex;
}

void  Player::SetTextureSegment(SDL_Texture* temptex) {
    segmenttex = temptex;
}