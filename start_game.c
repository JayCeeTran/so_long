#include "so_long.h"
//#include "/home/jaycee/minilibx-linux/mlx.h"

void	*start_game(t_game *game)
{
	game->mlx = mlx_init(64 * game->cols, 64 * game->rows, "Noa's Game", 1);
	if (game->mlx == NULL)
	{
		freemap(game);
		printf("failed to initialize Minilib");
		exit (1);
	}
	printf("are we after game initialization\n	collectible: %d\n", game->collectibles);
	load_texture_image(game);
	//mlx_image_to_window(game->mlx, game->images.start, 0, 0);
	
	//mlx_key_hook(game->win, space_to_start, game);
	
	drawmap(game);
	mlx_key_hook(game->mlx, keyhook, game);
	//mlx_hook(game->win, 17, 0, close_window, game);*/
	//mlx_hook(game->win, 22, 0, resize_window, game);

	return(game->mlx);
}
