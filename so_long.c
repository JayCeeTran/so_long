#include "so_long.h"

int	validate_argument(char *argv)
{
	int	len;
	
	len = ft_strlen(argv);
	if(ft_strncmp(argv + len - 4, ".ber", 4) == 0)
		return (1);
	return(0);
}

t_map **mallocmap(int rows, int col, char *argv, t_game *game)
{
	int i;
	t_map **map;

	i = 0;
	map = malloc(rows * sizeof(t_map *));
	if(!map)
		return(NULL);
	while(i < rows)
	{
		map[i] = ft_calloc(col + 1, sizeof(t_map));
		if(!map[i])
		{
			while(--i >= 0)
				free(map[i]);
			free(map);
			return(NULL);
		}
		i++;
	}
	if (!fillmap(map, argv, game))
		return (NULL);
	return(map);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc < 2)
		return (0);
	if(!validate_argument(argv[1]))
	{
		printf("Error invalid argument\n");
		return(0);
	}
	game.cols = is_map_size_valid(&game.rows, &game.cols, argv[1]);
	if (game.cols == -1 || !map_chars(argv[1]) || !map_walls(argv[1], game.rows, game.cols))
	{
		fprintf(stderr, "Error: Invalid map!\n");
		return(0);
	}
	game.map = mallocmap(game.rows, game.cols, argv[1], &game);
	if (!game.map)
		return(0);
	if(!valid_path(&game))
	{
		freemap(&game);
		printf("Error no path!\n");
		return(0);
	}
	int x = 0;
	int y = 0;
	while(x < game.rows)
	{
		y = 0;
		while(y < game.cols)
		{
			if(game.map[x][y].wall == 1)
				printf("1");
			else
				printf("0");
			y++;
		}
		printf("\n");
		x++;
	}
	if (!start_game(&game))
	{
		printf("starting game failed");
		return (0);
	}
	//mlx_key_hook(game.win, keyhook, &game);
	//mlx_hook(game.win, 22, 0, resize_window, &game);
	mlx_loop(game.mlx);
	printf("all good here\n");
	freemap(&game);
	return(0);

}
