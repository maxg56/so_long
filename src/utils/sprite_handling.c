/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:27:46 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/13 19:22:16 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_coordinates(t_game *game )
{
	int	tmp;

	tmp = game->player->position->x * TILE_SIZE;
	game->player->sprite->sprite->instances[0].x = tmp;
	tmp = game->player->position->y * TILE_SIZE;
	game->player->sprite->sprite->instances[0].y = tmp;
	game->player->sprite->sprite->instances[0].z = Z_DEFAULT_PLAYER;
}

void	set_instance_coordinates(mlx_image_t *sprite, int t,
			t_point *point, int z)
{
	sprite->instances[t].x = (point->x * TILE_SIZE);
	sprite->instances[t].y = (point->y * TILE_SIZE);
	if (z)
		sprite->instances[t].z = z;
}

void	set_instance_z(mlx_image_t *sprite, int t, int z)
{
	sprite->instances[t].z = z;
}
