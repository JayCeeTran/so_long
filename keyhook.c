#include "so_long.h"

void close_window(t_game *game)
{
	mlx_close_window(game->mlx);
	freemap(game);
	delete_images(game);
	exit (0);
}   

/*int	space_to_start(int keycode, void *param)
{
	t_game *game;

	game = (gamedata *)param;
	//if (keycode == 32)
	//	opengame(game);
	else if (keycode == 65307)
	{
		close_window(game);
		return (0);
	}

	return (0);
}*/
void	close_game(t_game *game)
{
		freemap(game);
		delete_images(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit (0);
}

void	keyhook(mlx_key_data_t keycode, void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	//printf("%d keypressed\n", keycode);
	if (keycode.key == 256 && keycode.action == MLX_PRESS)
		close_game(game);
	if ((keycode.key == 87 || keycode.key == 65 || keycode.key == 83 || keycode.key == 68) && keycode.action == MLX_PRESS)
		moving_keys(game, keycode);

}
