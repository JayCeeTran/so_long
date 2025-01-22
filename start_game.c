/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:48:33 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:45:39 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*start_game(t_game *game)
{
	game->action = 0;
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
		initialization_fail(game);
	load_texture_image(game);
	if (game->big == 0)
		drawmap(game);
	else
		drawmap_big(game);
	mlx_key_hook(game->mlx, keyhook, game);
	return (game->mlx);
}
