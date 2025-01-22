/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:48:23 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:46:17 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_argument(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(argv + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

t_map	**mallocmap(int rows, int col, char *argv, t_game *game)
{
	int		i;
	t_map	**map;

	i = 0;
	map = malloc(rows * sizeof(t_map *));
	if (!map)
		return (NULL);
	while (i < rows)
	{
		map[i] = ft_calloc(col + 1, sizeof(t_map));
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	if (!fillmap(map, argv, game))
		return (NULL);
	return (map);
}

void	invalid_argument(void)
{
	errno = EINVAL;
	perror("Error\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (0);
	if (!validate_argument(argv[1]))
		invalid_argument();
	game.cols = map_size(&game.rows, &game.cols, argv[1], 1);
	if (game.cols == -1 || !map_chars(argv[1]) || !map_walls(argv[1], game.rows,
			game.cols))
		invalid_map();
	game.map = mallocmap(game.rows, game.cols, argv[1], &game);
	if (!game.map)
		malloc_failed();
	if (!valid_path(&game))
		no_path(&game);
	start_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
