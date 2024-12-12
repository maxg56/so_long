/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 17:37:54 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void set_wall(t_game *game, int x, int y)
{
	static int instance_index = 0;

	if (instance_index == 0)
		game->map->sprite_void = open_image(PATH_SPRITE_WALL, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->map->sprite_void, x * TILE_SIZE, y * TILE_SIZE);
	set_instance_z(game->map->sprite_void, instance_index, Z_DEFAULT);
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

void	set_bak(t_game *game)
{
	int x;
	int y;
	
	y = 1;
	while (y < game->map->height - 1)
	{
		x = 1;
		while (x < game->map->width -1)
		{
			set_void(game, x, y, Z_BACKGROUND);
			x++;
		}
		y++;
	}
}
/*
void set_watr(t_game *game, int x, int y)
{
	static int instance_index = 0;

	if (instance_index == 0)
		game->map->sprite_watr = open_image(PATH_SPRITE_WOTRE, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->map->sprite_wall, x * TILE_SIZE, y * TILE_SIZE);
	set_instance_z(game->map->sprite_wall, instance_index, Z_DEFAULT);
	instance_index++;
}

void 	set_bordr(t_game *gme)
{
	int x;
	int y;

	y = 0;
	while (y < gme->map->height)
	{
		x = 0;
		while (x < gme->map->width)
		{
			if (y == 0 || y == gme->map->height - 1)
				set_watr(gme, x, y);
			else if (x == 0 || x == gme->map->width - 1)
				set_watr(gme, x, y);
			x++;
		}
		y++;
	}
}

*/
void	set_map(t_game *game)
{
	int	x;
	int	y;
	
	//set_bordr(game);
	set_bak(game);
	
	y = 1;
	while (y < game->map->height-1)
	{
		x = 1;
		while (x < game->map->width-1)
		{
			if (game->map->map_data[y][x] == WAll )
				set_wall(game, x, y);
			else if (game->map->map_data[y][x] == EXIT)
				set_exit(game, x, y);
			else if (game->map->map_data[y][x] == COLLECT)
				set_collectible(game, x, y);
			x++;
		}
		y++;
	}
}

