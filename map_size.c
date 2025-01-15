#include "so_long.h"

static int	colcount(int fd, int *row)
{
	char c;
	int col;

	col = 0;
	while(read(fd, &c, 1))
	{
		if(c == '\n')
			break;
		col++;
	}
	*row = 1;
	return(col);
}

int	is_map_size_valid(int *row, int *col, char *map)
{
	int byteread;
	char c;
	int valid;
	int	fd;

	fd = open(map, O_RDONLY);
	if(fd < 0)
		return(-1);
	byteread = 1;
	*col = 0;
	valid = colcount(fd, row);
	while (byteread > 0)
	{
		byteread = read(fd, &c, 1);
		(*col)++;
		if (c == '\n')
		{
			if(byteread == 0)
				break;
			if(((*col) - 1) != valid)
				return (-1);
			*col = 0;
			(*row)++;
		}
	}
	if(c != '\n')
		(*row)++;
	if((*row < 5 && valid < 3) || (*row < 3 && valid < 5))
		return (-1);
	close(fd);
	return(valid);
}
