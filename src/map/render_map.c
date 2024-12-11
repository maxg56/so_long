/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 22:40:24 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_sprite(t_game *game, int y, int x)
{
	if (game->maps->map[y][x] == PLAYER)
	{
		mlx_put_image_to_window(game->window->mlx, game->window->win, \
		game->player->ptr, (x * game->sprite_size), (y * game->sprite_size));
	}
	else if (game->maps->map[y][x] == EXIT)
	{
		game->->x = x * game->sprite_size;
		game->portal->y = y * game->sprite_size;
		mlx_put_image_to_window(game->window->mlx, game->window->win, \
		game->portal->ptr, (x * game->sprite_size), (y * game->sprite_size));
	}
	else if (game->maps->map[y][x] == '1')
		mlx_put_image_to_window(game->window->mlx, game->window->win, \
		game->wall->ptr, (x * game->sprite_size), (y * game->sprite_size));
	else if (game->maps->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->window->mlx, game->window->win, \
		game->collect->ptr, (x * game->sprite_size), (y * game->sprite_size));
	}
	else
		mlx_put_image_to_window(game->window->mlx, game->window->win, \
		game->floor->ptr, (x * game->sprite_size), (y * game->sprite_size));
}

void	render_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->maps->map[coord.y])
	{
		coord.x = 0;
		while (game->maps->map[coord.y][coord.x])
		{
			render_sprite(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	return ;
}

