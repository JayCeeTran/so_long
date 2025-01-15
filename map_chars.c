#include "so_long.h"

int	map_chars(char *map)	//Function checks if maptiles are valid.	
{							//Also check that there are Exit, Player and Collectible.
	int	fd;
	char	c;
	t_map tile;

	fd = open(map, O_RDONLY);
	if(fd < 0)
		return(0);
	ft_memset(&tile, 0, sizeof(tile));
	while(read(fd, &c, 1))
	{
		if (c != '\n' && c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0')
			return (0);
		if(c == 'P')
			tile.player++;
		else if (c == 'E')
			tile.exit++;
		else if (c == 'C')
			tile.collectible++;
	}
	if(tile.player != 1 || tile.exit != 1 || tile.collectible < 1)
		return (0);
	close(fd);
	return (1);
}
