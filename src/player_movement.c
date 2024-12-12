/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:35:11 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/12 15:17:22 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	if (game->map->map_data[game->player->position->y + y]\
        [game->player->position->x + x] == WAll)
		return ;
	game->player->position->x += x;
	game->player->position->y += y;
	game->player->move_count++;
	if (game->map->map_data[game->player->position->y][game->player->position->x] == COLLECT)
	{
		set_void(game, game->player->position->x, game->player->position->y, Z_DEFAULT + 1);
		game->map->info->collectibles--;
		game->map->map_data[game->player->position->y][game->player->position->x] = VOID;
	}
	if (game->map->map_data[game->player->position->y][game->player->position->x] == EXIT)
	{
		if (game->map->info->collectibles == 0)
			game->map->info->has_exit = TRUE;
	}
	ft_printf("Player move: %d \n", game->player->move_count);
	set_coordinates(game);
}
