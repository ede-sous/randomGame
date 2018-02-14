#include "randomGame.h"

void    playerPhysics(const GAME *game, float timeElapsed)
{
        game->player->hitbox.x += game->player->velX * timeElapsed;
        game->player->hitbox.y += game->player->velY * timeElapsed;
        game->player->velY += game->gravity * timeElapsed;
        
        

        if (game->player->hitbox.y + game->player->hitbox.h > WINDOW_HEIGHT)
        {
            game->player->hitbox.y = WINDOW_HEIGHT - game->player->hitbox.h;
            game->player->velY = 0.0f;
        }
        if (game->player->hitbox.y < 0)
            game->player->hitbox.y = 0;

        if (game->player->hitbox.x + game->player->hitbox.w > WINDOW_WIDTH)
            game->player->hitbox.x = WINDOW_WIDTH - game->player->hitbox.w;
        if (game->player->hitbox.x < 0)
            game->player->hitbox.x = 0;

}