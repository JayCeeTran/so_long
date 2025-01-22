/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:48:37 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 10:48:40 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path_helper(t_game *game, int x, int y, int *collectible)
{
	if (game->map[x][y].visited == 1 || game->map[x][y].wall == 1)
		return ;
	game->map[x][y].visited = 1;
	if (game->map[x][y].collectible == 1)
		(*collectible)--;
	if (x == game->exit.ei && y == game->exit.ej)
		game->exit.visited = 1;
	valid_path_helper(game, x + 1, y, collectible);
	valid_path_helper(game, x - 1, y, collectible);
	valid_path_helper(game, x, y + 1, collectible);
	valid_path_helper(game, x, y - 1, collectible);
}

int	valid_path(t_game *game)
{
	int	x;
	int	y;
	int	collectible;

	x = game->player.pi;
	y = game->player.pj;
	collectible = game->collectibles;
	valid_path_helper(game, x, y, &collectible);
	if (collectible == 0 && game->exit.visited == 1)
		return (1);
	return (0);
}

void	freemap(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->rows)
		free(game->map[x++]);
	free(game->map);
}
