/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:35:11 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/14 01:59:08 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_game *game)
{
	game->player->sprite->sprite = \
	open_image(PATH_SPRITE_PLAYER, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, \
					game->player->sprite->sprite, 0, 0);
	set_coordinates(game);
}

void	move_player(t_game *game, int x, int y)
{
	t_point	*point;

	if (game->map->map_data[game->player->position->y + y] \
		[game->player->position->x + x] == WAll)
		return ;
	game->player->position->x += x;
	game->player->position->y += y;
	game->player->move_count++;
	if (game->map->map_data[game->player->position->y] \
	[game->player->position->x] == COLLECT)
	{
		point = init_point();
		point->x = game->player->position->x;
		point->y = game->player->position->y;
		point->z = Z_DEFAULT + 1;
		choose_tatse(game, point);
		game->map->info->collectibles--;
		(game->map->map_data[game->player->position->y] \
		[game->player->position->x] = VOID, free(point));
	}
	if (game->map->map_data[game->player->position->y] \
	[game->player->position->x] == EXIT && game->map->info->collectibles == 0)
		game->game_satu = FALSE;
	(ft_printf("%d\n", game->player->move_count), set_coordinates(game));
}
