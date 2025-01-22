/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:45 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 10:39:58 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c(t_map *map, char c, t_game *game)
{
	if (c == 'C')
	{
		game->collectibles++;
		map->collectible = 1;
	}
	else if (c == 'E')
	{
		game->exit.ei = game->win_height;
		game->exit.ej = game->win_width;
		map->exit = 1;
	}
	else if (c == 'P')
	{
		game->player.pi = game->win_height;
		game->player.pj = game->win_width;
		map->player = 1;
	}
	else if (c == '1')
		map->wall = 1;
	else if (c == '0')
		map->empty = 1;
	else if (c == '\n')
		map->error = 1;
}

int	fillmap(t_map **map, char *argv, t_game *game)
{
	int		fd;
	char	c;

	game->collectibles = 0;
	game->win_height = 0;
	game->win_width = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1))
	{
		check_c(&map[game->win_height][game->win_width], c, game);
		game->win_width++;
		if (c == '\n')
		{
			game->win_height++;
			game->win_width = 0;
		}
	}
	close(fd);
	return (1);
}
