#include "randomGame.h"

CHARACTER *createCharacter(const GAME *game, char *skinPath, const SDL_Rect position)
{
    CHARACTER *player;

    if (!(player = (CHARACTER*)malloc(sizeof(CHARACTER))))
        return (NULL);
    if (!(player->skin = imageToTexture(skinPath, game->renderer)))
        return (NULL);
    player->hitbox.x = position.x;
    player->hitbox.y = position.y;
    SDL_QueryTexture(player->skin, NULL, NULL, &player->hitbox.w, &player->hitbox.h);
    if (player->hitbox.w > CHAR_WIDTH)
        player->hitbox.w = CHAR_WIDTH;
    if (player->hitbox.h > CHAR_HEIGHT)
        player->hitbox.h = CHAR_HEIGHT;
    player->velX = 0.0f;
    player->velY = 0.0f;
    return (player);
}