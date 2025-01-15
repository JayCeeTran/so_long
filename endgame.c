#include "so_long.h"

int	esc_or_x(int keycode, void *param)
{
	gamedata *game;

	game = (gamedata *)param;
	if (keycode == 65307)
	{
		close_window(game);
		return (0);
	}
	else
		mlx_key_hook(game->win, esc_or_x, game);
	return (0);
}

void	freestuff(gamedata *game)
{
	int	i;

	i = 0;
	while(i < game->rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void endgame(gamedata *game)
{
	freestuff(game);
	mlx_destroy_window(game->mlx, game->win);
	game->img = mlx_xpm_file_to_image(game->mlx, "textures/start.xpm", &game->win_width, &game->win_height);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Game Ended!");
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_key_hook(game->win, esc_or_x, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	
}
