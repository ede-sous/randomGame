#include "randomGame.h"

CHARACTER *createCharacter(const GAME *game, char *skinPath, const SDL_Rect position)
{
	CHARACTER *player;

	if (!(player = (CHARACTER*)malloc(sizeof(CHARACTER))))
		return (NULL);
	if (!(player->skin = imageToTexture(skinPath, game->renderer)))
		return (NULL);
	SDL_QueryTexture(player->skin, NULL, NULL, &player->hitbox.w, &player->hitbox.h);
	player->velX = 0.0f;
	player->velY = 0.0f;
	player->hitbox = (SDL_Rect){
									position.x,
									position.y,
									(player->hitbox.w > CHAR_WIDTH ? CHAR_WIDTH : player->hitbox.w),
									(player->hitbox.h > CHAR_HEIGHT ? CHAR_HEIGHT : player->hitbox.h)
								};
	return (player);
}