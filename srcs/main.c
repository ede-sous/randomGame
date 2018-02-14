#include "randomGame.h"

int		main(int argc, char *argv[])
{
	GAME	*game;
	int 	endState;

	if ((game = initSdl()) == NULL)
		return (1);
	endState = randomGame(game);
	return (endState);
}
