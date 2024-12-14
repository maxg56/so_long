/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:37:34 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/13 23:40:09 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(void)
{
	t_map	*map_struct;

	map_struct = malloc(sizeof(t_map));
	if (!map_struct)
		return (NULL);
	map_struct->map_data = NULL;
	map_struct->info = init_map_info();
	map_struct->width = 0;
	map_struct->height = 0;
	map_struct->sprite_void = init_sprite_map();
	map_struct->sprite_wall = init_sprite();
	map_struct->sprite_exit = init_sprite();
	map_struct->sprite_collect = init_sprite();
	map_struct->sprite_wotre = init_sprite();
	return (map_struct);
}

t_point	*init_point(void)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return (point);
}

t_player	*init_player(int x, int y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->position = init_point();
	if (!player->position)
		return (free(player), NULL);
	player->position->x = x;
	player->position->y = y;
	player->move_count = 0;
	player->health_points = 3;
	player->sprite = init_sprite();
	return (player);
}



t_map_info	*init_map_info(void)
{
	t_map_info	*info;

	info = malloc(sizeof(t_map_info));
	if (!info)
		return (NULL);
	info->has_player = FALSE;
	info->has_exit = FALSE;
	info->collectibles = 0;
	return (info);
}
