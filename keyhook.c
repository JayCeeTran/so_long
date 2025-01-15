#include "so_long.h"

int close_window(gamedata *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}   

int	space_to_start(int keycode, void *param)
{
	gamedata *game;

	game = (gamedata *)param;
	if (keycode == 32)
		opengame(game);
	else if (keycode == 65307)
	{
		close_window(game);
		return (0);
	}
	else
		mlx_key_hook(game->win, space_to_start, game);
	return (0);
}

int	keyhook(int keycode, void *param)
{
	gamedata *game;
	
	game = (gamedata *)param;
	printf("%d keypressed\n", keycode);
	if (keycode == 65307)
	{
		close_window(game);
		return (0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		moving_keys(game, keycode);

}
