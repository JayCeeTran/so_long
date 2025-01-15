#include "so_long.h"

int	map_walls(char *map, int row, int col) //Check that walls are 1.
{
	int	fd;
	int	ri;
	int	ci;
	char c;

	ri = 1;
	ci = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while(read(fd, &c, 1))
	{
		ci++;
		if (c == '\n')
		{
			ri++;
			ci = 0;
		}
		if ((ri == 1 || ri == row) && (ci >= 1 && ci <= col) && c != '1')
			return (0);
		else if ((ri >= 2 && ri <= row - 1) && (ci == 1 || ci == col) && c != '1')
			return (0);	
	}
	close (fd);
	return (1);
}
