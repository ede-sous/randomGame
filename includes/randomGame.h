#ifndef RANDOMGAME_H
#define RANDOMGAME_H

#include "randomConst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

typedef struct GAME
{
        SDL_Window          *window;
        SDL_Renderer        *renderer;
        const uint8_t       *keyboard;
        struct CHARACTER    *player;
        float               gravity;
}               GAME;

typedef struct CHARACTER
{
        SDL_Texture *skin;
        SDL_Rect    hitbox;
        float       velX;
        float       velY;
}               CHARACTER;

GAME            *initSdl(void);
int             randomGame(GAME *game);
CHARACTER       *createCharacter(const GAME *game, char *skinPath, const SDL_Rect position);
SDL_Texture     *imageToTexture(const char *path, SDL_Renderer *renderer);
void    playerPhysics(const GAME *game, float timeElapsed);
#endif
