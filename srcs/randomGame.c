#include "randomGame.h"

int     randomGame(GAME *game)
{
    SDL_Event event;
    SDL_Rect    p = {0, 0, 0, 0};
    Uint32 startClock = 0;
    Uint32 deltaClock = 0;

    game->player = createCharacter(game, "assets/blackSquare.png", p);
    game->gravity = 0.005f;
    if (!game->player)
        printf("error\n");
    while (1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;
        deltaClock = SDL_GetTicks() - startClock;
        playerPhysics(game, deltaClock);
        startClock = SDL_GetTicks();
        SDL_RenderCopy(game->renderer, game->player->skin, NULL, &game->player->hitbox);
        if (game->keyboard[SDL_SCANCODE_UP] && game->player->velY > -0.64f)
            game->player->velY += -0.16f;
        if (game->keyboard[SDL_SCANCODE_DOWN] && game->player->velY < 0.64f)
            game->player->velY += 0.16f;
        if (game->keyboard[SDL_SCANCODE_RIGHT] && game->keyboard[SDL_SCANCODE_LEFT] == 0)
            game->player->velX = 0.5f; 
        else if (game->keyboard[SDL_SCANCODE_LEFT] && game->keyboard[SDL_SCANCODE_RIGHT] == 0)
            game->player->velX = -0.5f;
        else
            game->player->velX = 0.0f;
        SDL_RenderPresent(game->renderer);
        SDL_RenderClear(game->renderer);
        SDL_Delay(10);
    }
    return (0);
}