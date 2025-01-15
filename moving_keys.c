#include "so_long.h"

int	w_valid_move(gamedata *game, int pi)
{
	int	i;
	int	j;

	i = game->player.pi;			// pi = rows - 1
	j = game->player.pj;
	if (!game->map[pi][j].wall)
	{
		game->map[i][j].player = 0;
		game->map[i][j].empty = 1;
		game->player.pi = pi;
		game->map[pi][j].player = 1;
		game->map[pi][j].empty = 0;
		game->map[pi][j].collectible = 0;
	}
	drawmap(game);
	if (!game->collectibles)
	{
		if (game->map[pi][j].exit == 1)
			endgame(game);
	}
}

int	s_valid_move(gamedata *game, int pi)
{
	int	i;
	int	j;

	i = game->player.pi;			// pi = rows + 1
	j = game->player.pj;
	if (!game->map[pi][j].wall)
	{
		game->map[i][j].player = 0;
		game->map[i][j].empty = 1;
		game->player.pi = pi;
		game->map[pi][j].player = 1;
		game->map[pi][j].empty = 0;
		game->map[pi][j].collectible = 0;
	}
	drawmap(game);
	if (!game->collectibles)
	{
		if (game->map[pi][j].exit == 1)
			endgame(game);
	}
}

int	a_valid_move(gamedata *game, int pj)
{
	int	i;
	int	j;

	i = game->player.pi;			// pj = cols - 1
	j = game->player.pj;
	if (!game->map[i][pj].wall)
	{
		game->map[i][j].player = 0;
		game->map[i][j].empty = 1;
		game->player.pj = pj;
		game->map[i][pj].player = 1;
		game->map[i][pj].empty = 0;
		game->map[i][pj].collectible = 0;
	}
	drawmap(game);
	if (!game->collectibles)
	{
		if (game->map[i][pj].exit == 1)
			endgame(game);
	}
	return (0);
}

int	d_valid_move(gamedata *game, int pj)
{
	int	i;
	int	j;

	i = game->player.pi;			// pi = cols + 1
	j = game->player.pj;
	if (!game->map[i][pj].wall)
	{
		game->map[i][j].player = 0;
		game->map[i][j].empty = 1;
		game->player.pj = pj;
		game->map[i][pj].player = 1;
		game->map[i][pj].empty = 0;
		game->map[i][pj].collectible = 0;
	}
	drawmap(game);
	if (!game->collectibles)
	{
		if (game->map[i][pj].exit == 1)
			endgame(game);
	}
	return (0);
}

void	moving_keys(gamedata *game, int keycode)
{
	if(keycode == 119)
	{
		w_valid_move(game, game->player.pi - 1);
	}
	else if (keycode == 97)
		a_valid_move(game, game->player.pj - 1);
	else if (keycode == 115)
		s_valid_move(game, game->player.pi + 1);
	else if (keycode == 100)
		d_valid_move(game, game->player.pj + 1);
	
}
