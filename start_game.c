#include "so_long.h"

void	*start_game(t_game *game)
{
	game->lastc = 1;
	game->big = 1;
	if (game->cols <= 15 && game->rows <= 11)
	{
		game->big = 0;
		game->mlx = mlx_init(64 * game->cols, 64 * game->rows, "Noa's Game", 1);
	}
	else
		game->mlx = mlx_init(64 * 15, 64 * 11, "Noa's Game", 1);
	if (game->mlx == NULL)
	{
		freemap(game);
		printf("failed to initialize Minilib");
		exit (1);
	}
	load_texture_image(game);
	if (game->big == 0)
		drawmap(game);
	else
		drawmap_big(game);
	mlx_key_hook(game->mlx, keyhook, game);
	return(game->mlx);
}
