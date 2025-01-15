#include "so_long.h"
//#include "/home/jaycee/minilibx-linux/mlx.h"

void	*start_game(gamedata *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		printf("failed to initialize Minilib");
		return (NULL);
	}
	game->img = mlx_xpm_file_to_image(game->mlx, "textures/start.xpm", &game->win_width, &game->win_height);
	if(game->img == NULL)
	{
		printf("Cant load image");
		return(NULL);
	}
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Noa Collecting");
	if (game->win == NULL)
	{
		printf("Cannot open window");
		return (NULL);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	load_image(game);
	mlx_key_hook(game->win, space_to_start, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	//mlx_hook(game->win, 22, 0, resize_window, game);

	return(game->mlx);
}
