/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 02:52:42 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"





void	set_bak(t_game *game)
{
	t_point *point;

	point = init_point();
	point->z = Z_BACKGROUND;
	point->y = 1;
	while (point->y < game->map->height - 1)
	{
		point->x = 1;
		while (point->x < game->map->width -1)
		{
			choose_tatse(game, point);
			point->x++;
		}
		point->y++;
	}
}

void	set_map(t_game *game)
{
	t_point	*point;

	set_bak(game);
	point = init_point();
	point->z = Z_DEFAULT;
	point->y = 0;
	while (point->y < game->map->height)
	{
		point->x = 0;
		while (point->x < game->map->width)
		{
			if ( point->x == 0 || point->x == game->map->width - 1 ||
				point->y == 0 || point->y == game->map->height - 1)
				set_tlse(game, game->map->sprite_wotre, point, PATH_SPRITE_WOTRE);
			else
			if (game->map->map_data[point->y][point->x] == WAll )
				set_tlse(game, game->map->sprite_wall, point, PATH_SPRITE_WALL);
			else if (game->map->map_data[point->y][point->x] == EXIT )
				set_tlse(game, game->map->sprite_exit, point, PATH_SPRITE_EXIT);
			else if (game->map->map_data[point->y][point->x] == COLLECT )
				set_tlse(game, game->map->sprite_collect, point, PATH_SPRITE_COLLECT);
			point->x++;
		}
		point->y++;
	}
}

