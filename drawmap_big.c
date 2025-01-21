#include "so_long.h"

void    check_struct_big(t_map map, t_game *game, int i, int j)
{

    if (map.wall)
        mlx_image_to_window(game->mlx, game->images.wall, j * game->tilesize, i * game->tilesize);
    else if(map.player)
        mlx_image_to_window(game->mlx, game->images.player, j * game->tilesize, i * game->tilesize);
    else if(map.exit)
        mlx_image_to_window(game->mlx, game->images.exit, j * game->tilesize, i * game->tilesize);
    else if(map.empty)
        mlx_image_to_window(game->mlx, game->images.empty, j * game->tilesize, i * game->tilesize);
    else if(map.collectible)
        mlx_image_to_window(game->mlx, game->images.collectible, j * game->tilesize, i * game->tilesize);
}

void    drawmap_big(t_game *game)
{
    int i;
    int j;
	int x;
	int y;

	i = 0;
	x = 0;
	if(game->player.pi > 5)
		i = game->player.pi - 5;
	while(x < 11)
    {
        j = 0;
		y = 0;
		if(game->player.pj > 7)
			j = game->player.pj - 7;
        while(y < 15)
        {
			if(i < game->rows && j < game->cols)
				check_struct_big(game->map[i][j++], game, x, y++);
			else
				mlx_image_to_window(game->mlx, game->images.wall, y++ * game->tilesize, x * game->tilesize);
        }
        i++;
		x++;
    }    
}
