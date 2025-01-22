/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:08:04 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:54:33 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(void)
{
	write(2, "Error\nInvalid Map!\n", 19);
	exit(1);
}

void	no_path(t_game *game)
{
	freemap(game);
	write(2, "Error\nNo Path!\n", 15);
	exit(1);
}

void	initialization_fail(t_game *game)
{
	freemap(game);
	write(2, "Error\nFailed to initialize MLX42\n", 33);
	exit(1);
}

void	malloc_failed(void)
{
	write(2, "Error\nMalloc Failed!\n", 21);
	exit(1);
}
