/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:39:56 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:21:46 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	colcount(int fd, int *row)
{
	char	c;
	int		col;

	col = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		col++;
	}
	*row = 1;
	return (col);
}

void	open_file(int *fd, char *map)
{
	*fd = open(map, O_RDONLY);
	if (*fd < 0)
	{
		write(2, "Error\nOpening File\n", 19);
		exit(1);
	}
}

void	minimum_size(int *row, int *col, int valid, int c)
{
	if (c != '\n')
		(*row)++;
	if ((*row < 5 && valid < 3) || (*row < 3 && valid < 5))
	{
		write(2, "Error\nSmaller than minimum size map\n", 36);
		exit(1);
	}
}

int	map_size(int *row, int *col, char *map, int byteread)
{
	char	c;
	int		valid;
	int		fd;

	open_file(&fd, map);
	*col = 0;
	valid = colcount(fd, row);
	while (byteread > 0)
	{
		byteread = read(fd, &c, 1);
		(*col)++;
		if (c == '\n')
		{
			if (byteread == 0)
				break ;
			if (((*col) - 1) != valid)
				return (-1);
			*col = 0;
			(*row)++;
		}
	}
	minimum_size(row, col, valid, c);
	close(fd);
	return (valid);
}
