#include "so_long.h"

void	initialize_directions(int directions[4][2])
{
	directions[0][0] = 1;
	directions[0][1] = 0;
	directions[1][0] = -1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
}

void	check_malloc(t_game *game, int *queue_x, int *queue_y, int *queue_distance)
{
	if(!queue_x || !queue_y || !queue_distance)
	{
		free(queue_x);
		free(queue_y);
		free(queue_distance);
		freemap(game);
		delete_images(game);
		perror("Error:");
		exit(1);
	}
}

void	free_queues(int *queue_x, int *queue_y, int *queue_distance)
{
	free(queue_x);
	free(queue_y);
	free(queue_distance);
}

void	short_path_helper(t_game *game, int *queue_x, int *queue_y, int *queue_distance)
{
	int directions[4][2];
	int	dir;
	int new_x;
	int new_y;

	dir = 0;
	initialize_directions(directions);
	while (dir < 4)
    {
        new_x = game->shortp.cur_x + directions[dir][0];
        new_y = game->shortp.cur_y + directions[dir][1];
        if (game->map[new_x][new_y].visited == 0 && game->map[new_x][new_y].wall == 0)
        {
            game->map[new_x][new_y].visited = 1;
            queue_x[game->shortp.rear] = new_x;
            queue_y[game->shortp.rear] = new_y;
            queue_distance[game->shortp.rear] = game->shortp.dist + 1;
            game->shortp.rear++;
        }
        dir++;
    }
}

void short_path(t_game *game, int front)
{
    int *queue_x;
    int *queue_y;
    int *queue_distance;

	queue_x = malloc(game->rows * game->cols * sizeof(int));
	queue_y = malloc(game->rows * game->cols * sizeof(int));
	queue_distance = malloc(game->rows * game->cols * sizeof(int));
	check_malloc(game, queue_x, queue_y, queue_distance);
    queue_x[game->shortp.rear] = game->player.pi;
    queue_y[game->shortp.rear] = game->player.pj;
    queue_distance[game->shortp.rear++] = 0;
    game->map[game->player.pi][game->player.pj].visited = 1;
    while (front < game->shortp.rear)
    {
        game->shortp.cur_x = queue_x[front];
        game->shortp.cur_y = queue_y[front];
        game->shortp.dist = queue_distance[front++];
        if (game->shortp.cur_x == game->exit.ei && game->shortp.cur_y == game->exit.ej)
        {
            game->shortest = game->shortp.dist;
			free_queues(queue_x, queue_y, queue_distance);
            return;
        }
        short_path_helper(game, queue_x, queue_y, queue_distance); 
    }
}
