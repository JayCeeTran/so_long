#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
typedef struct s_point{
	int x;
	int y;
} t_point;

typedef struct s_player{
	int pi;
	int pj;
} t_player;

typedef struct t_exit{
	int ei;
	int ej;
	int visited;
} t_exit;

typedef struct s_map{
	int	wall;
	int empty;
	int	collectible;
	int	exit;
	int error;
	int	player;
	int visited;
} t_map;

typedef struct s_texture{
	mlx_texture_t *start;
	mlx_texture_t *wall;
	mlx_texture_t *empty;
	mlx_texture_t *collectible;
	mlx_texture_t *exit;
	mlx_texture_t *player;
} t_texture;

typedef struct s_image{
	mlx_image_t	*start;
    mlx_image_t	*wall;
    mlx_image_t	*empty;
    mlx_image_t	*collectible;
    mlx_image_t	*exit;
    mlx_image_t	*player;
} t_image;

typedef struct s_game{
    mlx_t    *mlx;
    void    *win;
	int		collectibles;
	int		tilesize;
	int     win_width;
    int     win_height;
	int		rows;
	int		cols;
	t_image images;
	t_map	**map;
	t_player player;
	t_exit	exit;
} t_game;

int is_map_size_valid(int *row, int *col, char *map);
int	map_chars(char *map);
int	map_walls(char *map, int row, int col);
int	fillmap(t_map **map, char *argv, t_game *game);
int valid_path(t_game *game);
void	freemap(t_game *game);
void	delete_images(t_game *game);
void *start_game(t_game *game);
void	close_game(t_game *game);
void	load_texture_image(t_game *game);
void	drawmap(t_game *game);
void	keyhook(mlx_key_data_t keycode, void *param);
void	moving_keys(t_game *game, mlx_key_data_t keycode);
/*int	space_to_start(int keycode, void *param);
int	keyhook(int keycode, void *param);

int resize_window(gamedata *game);

void	moving_keys(gamedata *game, int keycode);
void	drawmap(gamedata *game);
void	opengame(gamedata *game);
void	endgame(gamedata *game);*/

#endif
