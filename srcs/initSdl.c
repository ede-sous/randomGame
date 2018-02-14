#include "randomGame.h"

GAME    *initSdl(void)
{
    GAME *game;

    if (!(game = (GAME*)malloc(sizeof(GAME))))
        return (NULL);
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error\n");
		return (NULL);
	}
    if (!(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) & (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)))
    {
        printf("Error with sdl image\n");
        return (NULL);
    }
	if ((game->window = SDL_CreateWindow("randomGame",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
	{
		printf("Error Create a window\n");
		return (NULL);
	}
	if ((game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
		printf("Error creating a renderer\n");
		return (NULL);
	}
    game->keyboard = SDL_GetKeyboardState(NULL);
    SDL_SetRenderDrawColor(game->renderer, 100, 100, 100, 255);
    return (game);
}