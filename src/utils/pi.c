/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:27:46 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 08:37:13 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


void	set_corde(t_game *game )
{
	game->player->sprite->instances[0].x = (game->player->point->x * 64);
	game->player->sprite->instances[0].y = (game->player->point->y * 64);
	game->player->sprite->instances[0].z = 3;	
}

void set_corde_inst(mlx_image_t *sprite, int t, t_point *point, int z)
{

	sprite->instances[t].x = (point->x * 64);
	sprite->instances[t].y = (point->y * 64);
	if (z)
		sprite->instances[t].z = z;
}

void	set_z(mlx_image_t *sprite,int t, int z)
{
	sprite->instances[t].z = z;
}

void	move_player(t_game *game, int x, int y)
{
	if (game->maps->map[game->player->point->y + y][game->player->point->x + x] \
		== MUR)
		return ;
	game->player->point->x += x;
	game->player->point->y += y;
	game->player->moves++;
	if (game->maps->map[game->player->point->y][game->player->point->x] == COLLECT)
	{
		game->maps->map[game->player->point->y][game->player->point->x] = VIDE;
		game->maps->info->collect--;
	}
	if (game->maps->map[game->player->point->y][game->player->point->x] == EXIT)
	{
		game->maps->info->exit = TRUE;
	}
	set_corde(game);
}
