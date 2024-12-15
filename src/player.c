/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:35:11 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/15 07:09:25 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_game *game)
{
	if (!game || !game->player || !game->player->sprite)
		exit_error("Player or sprite not initialized");
	game->player->sprite->sprite = open_image(PATH_SPRITE_PLAYER, \
	game->window->mlx_instance);
	if (!game->player->sprite->sprite)
		exit_error("Failed to load player sprite");
	mlx_image_to_window(game->window->mlx_instance, \
	game->player->sprite->sprite, 0, 0);
	set_coordinates(game);
}


static void	colletible(t_game *game)
{
	t_point	*point;

	point = init_point();
	point->x = game->player->position->x;
	point->y = game->player->position->y;
	point->z = Z_DEFAULT + 1;
	choose_tatse(game, point);
	game->map->info->collectibles--;
	(game->map->map_data[game->player->position->y] \
	[game->player->position->x] = VOID);
}

void	set_move(t_game *game)
{
	char	*move;

	move = ft_strjoin("move : ", ft_itoa(game->player->move_count));
	if (game->sprite_move)
		mlx_delete_image(game->window->mlx_instance, game->sprite_move);
	game->sprite_move = mlx_put_string(game->window->mlx_instance, \
	move, 25, 15);
	game->sprite_move->instances[0].z = Z_DEFAULT_UI +1;
}

void	set_pv(t_game *game)
{
	char	*pv;

	pv = ft_strjoin("pv : ", ft_itoa(game->player->health_points));
	if (game->sprite_pv)
		mlx_delete_image(game->window->mlx_instance, game->sprite_pv);
	game->sprite_pv = mlx_put_string(game->window->mlx_instance, \
	pv, TILE_SIZE + 50, 15);
	game->sprite_pv->instances[0].z = Z_DEFAULT_UI +1;
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map->map_data[game->player->position->y + y] \
		[game->player->position->x + x] == WAll)
		return ;
	game->player->position->x += x;
	game->player->position->y += y;
	game->player->move_count++;
	if (game->map->map_data[game->player->position->y] \
	[game->player->position->x] == COLLECT)
		colletible(game);
	else if (game->map->map_data[game->player->position->y] \
	[game->player->position->x] == EXIT && game->map->info->collectibles == 0)
		game->game_satu = FALSE;
	set_move(game);
	set_pv(game);
	set_coordinates(game);
}
