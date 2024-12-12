/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:37:34 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/12 11:30:01 by max_dev          ###   ########.fr       */
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
	return (map_struct);
}

t_player	*init_player(int x, int y, void *sprite)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->position = malloc(sizeof(t_point));
	if (!player->position)
		return (free(player), NULL);
	player->position->x = x;
	player->position->y = y;
	player->move_count = 0;
	player->health_points = 3;
	player->sprite = sprite;
	return (player);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->window = NULL;
	game->map = NULL;
	game->player = init_player(0, 0, NULL);
	if (!game->player)
		return (free(game), NULL);
	return (game);
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