/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 12:07:47 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void set_wall(t_game *game, int x, int y)
{
	static int instance_index = 0;

	if (instance_index == 0)
		game->map->sprite_wall = open_image(PATH_SPRITE_WALL, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->map->sprite_wall, x * TILE_SIZE, y * TILE_SIZE);
	set_instance_z(game->map->sprite_wall, instance_index, Z_DEFAULT);
	instance_index++;
}

void	set_void(t_game *game, int x, int y , int z)
{
	static int instance_index = 0;

	if (instance_index == 0)
		game->map->sprite_wall = open_image(PATH_SPRITE_VOID, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->map->sprite_wall, x * TILE_SIZE, y * TILE_SIZE);
	set_instance_z(game->map->sprite_wall, instance_index, z);
	instance_index++;
}

static void	set_exit(t_game *game, int x, int y)
{
	
	game->map->sprite_exit = open_image(PATH_SPRITE_EXIT, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->map->sprite_exit, x * TILE_SIZE, y * TILE_SIZE);
	set_instance_z(game->map->sprite_exit, 0, Z_DEFAULT);
}

static void	set_collectible(t_game *game, int x, int y)
{
	static int instance_index = 0;

	if (instance_index == 0)
		game->map->sprite_collect = open_image(PATH_SPRITE_COLLECT, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->map->sprite_collect, x * TILE_SIZE, y * TILE_SIZE);
	set_instance_z(game->map->sprite_collect, instance_index, Z_DEFAULT);
	instance_index++;
}
void	set_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map_data[y][x] == WAll )
				set_wall(game, x, y);
			else if (game->map->map_data[y][x] == EXIT)
				set_exit(game, x, y);
			else if (game->map->map_data[y][x] == COLLECT)
				set_collectible(game, x, y);
			else if (game->map->map_data[y][x] == VOID)
				set_void(game, x, y, Z_DEFAULT);
			x++;
		}
		y++;
	}
}

