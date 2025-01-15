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

typedef struct s_game{
    void    *mlx;
    void    *win;
	void	*img;
    void    *img_wall;
    void    *img_empty;
    void    *img_collectible;
    void    *img_exit;
    void    *img_player;
	int		collectibles;
	int		tilesize;
	int     win_width;
    int     win_height;
	int		rows;
	int		cols;
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
void *start_game(t_game *game);
int	close_window(t_game *game);

/*int	space_to_start(int keycode, void *param);
int	keyhook(int keycode, void *param);
int	load_image(gamedata *game);
int resize_window(gamedata *game);

void	moving_keys(gamedata *game, int keycode);
void	drawmap(gamedata *game);
void	opengame(gamedata *game);
void	endgame(gamedata *game);*/

#endif
