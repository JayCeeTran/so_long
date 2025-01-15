#include "so_long.h"

void    check_struct(maps map, gamedata *game, int i, int j)
{
    if (map.wall)
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * game->tilesize, i * game->tilesize);
    else if(map.player)
    {
        game->player.pi = i;
        game->player.pj = j;
        mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * game->tilesize, i * game->tilesize);
    }
    else if(map.exit)
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * game->tilesize, i * game->tilesize);
    else if(map.empty)
        mlx_put_image_to_window(game->mlx, game->win, game->img_empty, j * game->tilesize, i * game->tilesize);
    else if(map.collectible)
    {
        game->collectibles++;
        mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, j * game->tilesize, i * game->tilesize);
    }
}

void    drawmap(gamedata *game)
{
    int i = 0;
    int j = 0;

    game->collectibles = 0;
    while(i < game->rows)
    {
        j = 0;
        while(j < game->cols)
        {
            check_struct(game->map[i][j], game, i, j);
            j++;
        }
        i++;
    }
    mlx_key_hook(game->win, keyhook, game);
}

void    opengame(gamedata *game)
{
    int i = 0;
    int j = 0;

    mlx_destroy_window(game->mlx, game->win);
    game->win = mlx_new_window(game->mlx, game->cols * game->tilesize, game->rows * game->tilesize, "Noa Collecting");
    while(i < game->rows)
    {
        j = 0;
        while(j < game->cols)
        {
            check_struct(game->map[i][j], game, i, j);
            j++;
        }
        i++;
    }
    mlx_key_hook(game->win, keyhook, game);
	mlx_hook(game->win, 17, 0, close_window, game);
}
