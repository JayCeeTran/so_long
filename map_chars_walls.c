/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:51 by jtran             #+#    #+#             */
/*   Updated: 2025/01/17 10:36:18 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_chars(char *map)
{
	int		fd;
	char	c;
	t_map	tile;

	open_file(&fd, map);
	ft_memset(&tile, 0, sizeof(tile));
	while (read(fd, &c, 1))
	{
		if (c != '\n' && c != 'C' && c != 'E' && c != 'P' && c != '1'
			&& c != '0')
			return (0);
		if (c == 'P')
			tile.player++;
		else if (c == 'E')
			tile.exit++;
		else if (c == 'C')
			tile.collectible++;
	}
	if (tile.player != 1 || tile.exit != 1 || tile.collectible < 1)
		return (0);
	close(fd);
	return (1);
}

int	map_walls(char *map, int row, int col)
{
	int		fd;
	int		ri;
	int		ci;
	char	c;

	ri = 1;
	ci = 0;
	open_file(&fd, map);
	while (read(fd, &c, 1))
	{
		ci++;
		if (c == '\n')
		{
			ri++;
			ci = 0;
		}
		if ((ri == 1 || ri == row) && (ci >= 1 && ci <= col) && c != '1')
			return (0);
		else if ((ri >= 2 && ri <= row - 1) && (ci == 1 || ci == col)
			&& c != '1')
			return (0);
	}
	close(fd);
	return (1);
}
