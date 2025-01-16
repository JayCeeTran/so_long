#include "so_long.h"

int	w_valid_move(t_game *game, int pi)
{
	int	i;
	int	j;

	i = game->player.pi;			// pi = rows - 1
	j = game->player.pj;
	if (!game->map[pi][j].wall)
	{
		if(game->map[pi][j].collectible == 1)
			game->collectibles--;
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
		if (j == game->exit.ej && pi == game->exit.ei)
			close_game(game);
	}
}

int	s_valid_move(t_game *game, int pi)
{
	int	i;
	int	j;

	i = game->player.pi;			// pi = rows + 1
	j = game->player.pj;
	if (!game->map[pi][j].wall)
	{
		if(game->map[pi][j].collectible == 1)
			game->collectibles--;
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
		if (j == game->exit.ej && pi == game->exit.ei)
			close_game(game);
	}
}

int	a_valid_move(t_game *game, int pj)
{
	int	i;
	int	j;

	i = game->player.pi;			// pj = cols - 1
	j = game->player.pj;
	if (!game->map[i][pj].wall)
	{
		if(game->map[i][pj].collectible == 1)
			game->collectibles--;
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
			close_game(game);
	}
	return (0);
}

int	d_valid_move(t_game *game, int pj)
{
	int	i;
	int	j;

	i = game->player.pi;			// pi = cols + 1
	j = game->player.pj;
	if (!game->map[i][pj].wall)
	{
		if(game->map[i][pj].collectible == 1)
			game->collectibles--;
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
			close_game(game);
	}
	return (0);
}

void	moving_keys(t_game *game, mlx_key_data_t keycode)
{
	//printf("%d collect\n", game->collectibles);
	//printf("%d %d exit\n", game->exit.ei, game->exit.ej);
	if(keycode.key == 87)
		w_valid_move(game, game->player.pi - 1);
	else if (keycode.key == 65)
		a_valid_move(game, game->player.pj - 1);
	else if (keycode.key == 83)
		s_valid_move(game, game->player.pi + 1);
	else if (keycode.key == 68)
		d_valid_move(game, game->player.pj + 1);
	
}
