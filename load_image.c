#include "so_long.h"

int	load_image(gamedata *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->win_width, &game->win_height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &game->win_width, &game->win_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/poop.xpm", &game->win_width, &game->win_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->win_width, &game->win_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->win_width, &game->win_height);
	if(!game->img_wall || !game->img_empty || !game->img_collectible || !game->img_exit || !game->img_player)
	{
		printf("Error loading images\n");
		return (0);
	}
	game->tilesize = game->win_width;
	return (1);
}
