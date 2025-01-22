/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:40:19 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:21:42 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_texture(t_texture *texture)
{
	mlx_delete_texture(texture->wall);
	mlx_delete_texture(texture->empty);
	mlx_delete_texture(texture->collectible);
	mlx_delete_texture(texture->exit);
	mlx_delete_texture(texture->player);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->images.wall);
	mlx_delete_image(game->mlx, game->images.empty);
	mlx_delete_image(game->mlx, game->images.exit);
	mlx_delete_image(game->mlx, game->images.collectible);
	mlx_delete_image(game->mlx, game->images.player);
}

void	load_image(t_game *game, t_texture *texture)
{
	game->images.wall = mlx_texture_to_image(game->mlx, texture->wall);
	game->images.empty = mlx_texture_to_image(game->mlx, texture->empty);
	game->images.exit = mlx_texture_to_image(game->mlx, texture->exit);
	game->images.collectible = mlx_texture_to_image(game->mlx,
			texture->collectible);
	game->images.player = mlx_texture_to_image(game->mlx, texture->player);
	if (!game->images.wall || !game->images.empty || !game->images.collectible
		|| !game->images.exit || !game->images.player)
	{
		delete_images(game);
		delete_texture(texture);
		freemap(game);
		write(2, "Error\nFailed to load images\n", 28);
		exit(1);
	}
}

void	load_texture_image(t_game *game)
{
	t_texture	textures;

	textures.wall = mlx_load_png("textures/tree.png");
	textures.empty = mlx_load_png("textures/empty.png");
	textures.collectible = mlx_load_png("textures/Taide.png");
	textures.exit = mlx_load_png("textures/Ditto.png");
	textures.player = mlx_load_png("textures/Player.png");
	if (!textures.wall || !textures.empty || !textures.collectible
		|| !textures.exit || !textures.player)
	{
		delete_texture(&textures);
		freemap(game);
		write(2, "Error\nFailed to create textures!\n", 33);
		exit(1);
	}
	load_image(game, &textures);
	delete_texture(&textures);
	game->tilesize = game->images.wall->width;
}
