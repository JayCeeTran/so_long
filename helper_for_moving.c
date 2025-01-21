#include "so_long.h"

void	change_struct_flags(t_game *game, int pi)
{
	int i;
    int j;

    i = game->player.pi;            
    j = game->player.pj;
		if(game->map[pi][j].collectible == 1)
            game->collectibles--;
        game->map[i][j].player = 0;
        game->map[i][j].empty = 1;
        game->player.pi = pi;
        game->map[pi][j].player = 1;
        game->map[pi][j].empty = 0;
        game->map[pi][j].collectible = 0;
}

void	change_struct_flags_2(t_game *game, int pj)
{
	int i;
    int j;

    i = game->player.pi;            
    j = game->player.pj;
		if(game->map[i][pj].collectible == 1)
            game->collectibles--;
        game->map[i][j].player = 0;
        game->map[i][j].empty = 1;
        game->player.pj = pj;
        game->map[i][pj].player = 1;
        game->map[i][pj].empty = 0;
        game->map[i][pj].collectible = 0;
}
