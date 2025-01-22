/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:29 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 10:39:43 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_struct(t_map map, t_game *game, int i, int j)
{
	if (map.wall)
		mlx_image_to_window(game->mlx, game->images.wall, j * game->tilesize, i
			* game->tilesize);
	else if (map.player)
		mlx_image_to_window(game->mlx, game->images.player, j * game->tilesize,
			i * game->tilesize);
	else if (map.exit)
		mlx_image_to_window(game->mlx, game->images.exit, j * game->tilesize, i
			* game->tilesize);
	else if (map.empty)
		mlx_image_to_window(game->mlx, game->images.empty, j * game->tilesize, i
			* game->tilesize);
	else if (map.collectible)
		mlx_image_to_window(game->mlx, game->images.collectible, j
			* game->tilesize, i * game->tilesize);
}

void	drawmap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			check_struct(game->map[i][j], game, i, j);
			j++;
		}
		i++;
	}
}
