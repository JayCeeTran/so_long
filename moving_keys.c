/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:40:29 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:54:53 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_valid_move(t_game *game, int pi)
{
	int	i;
	int	j;

	i = game->player.pi;
	j = game->player.pj;
	if (!game->map[pi][j].wall)
	{
		game->moves++;
		change_struct_flags(game, pi);
	}
	if (game->big)
		drawmap_big(game);
	else
		drawmap(game);
	if (!game->collectibles)
	{
		if (j == game->exit.ej && pi == game->exit.ei)
		{
			if (game->moves <= game->shortest)
				win_game(game);
			else
				lose_game(game);
		}
	}
}

void	s_valid_move(t_game *game, int pi)
{
	int	i;
	int	j;

	i = game->player.pi;
	j = game->player.pj;
	if (!game->map[pi][j].wall)
	{
		game->moves++;
		change_struct_flags(game, pi);
	}
	if (game->big)
		drawmap_big(game);
	else
		drawmap(game);
	if (!game->collectibles)
	{
		if (j == game->exit.ej && pi == game->exit.ei)
		{
			if (game->moves <= game->shortest)
				win_game(game);
			else
				lose_game(game);
		}
	}
}

void	a_valid_move(t_game *game, int pj)
{
	int	i;
	int	j;

	i = game->player.pi;
	j = game->player.pj;
	if (!game->map[i][pj].wall)
	{
		game->moves++;
		change_struct_flags_2(game, pj);
	}
	if (game->big)
		drawmap_big(game);
	else
		drawmap(game);
	if (!game->collectibles)
	{
		if (game->map[i][pj].exit == 1)
		{
			if (game->moves <= game->shortest)
				win_game(game);
			else
				lose_game(game);
		}
	}
}

void	d_valid_move(t_game *game, int pj)
{
	int	i;
	int	j;

	i = game->player.pi;
	j = game->player.pj;
	if (!game->map[i][pj].wall)
	{
		game->moves++;
		change_struct_flags_2(game, pj);
	}
	if (game->big)
		drawmap_big(game);
	else
		drawmap(game);
	if (!game->collectibles)
	{
		if (game->map[i][pj].exit == 1)
		{
			if (game->moves <= game->shortest)
				win_game(game);
			else
				lose_game(game);
		}
	}
}

void	moving_keys(t_game *game, mlx_key_data_t keycode)
{
	if (keycode.key == 87)
		w_valid_move(game, game->player.pi - 1);
	else if (keycode.key == 65)
		a_valid_move(game, game->player.pj - 1);
	else if (keycode.key == 83)
		s_valid_move(game, game->player.pi + 1);
	else if (keycode.key == 68)
		d_valid_move(game, game->player.pj + 1);
}
