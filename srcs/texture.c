#include "randomGame.h"

SDL_Texture     *imageToTexture(const char *path, SDL_Renderer *renderer)
{
    SDL_Surface     *surface = NULL;
    SDL_Texture     *texture = NULL;

    if (!path || !renderer)
        return (NULL);
    if (!(surface = IMG_Load(path)))
        return (NULL);
    if (!(texture = SDL_CreateTextureFromSurface(renderer, surface)))
        return (NULL);
    SDL_FreeSurface(surface);
    surface = NULL;
    return (texture);
}