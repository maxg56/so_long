/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 20:59:18 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_background_tiles(t_game *g)
{
	t_point	*point;

	point = init_point();
	point->z = Z_BACKGROUND;
	point->y = 0;
	while (point->y <= g->map->height - 1)
	{
		point->x = 0;
		while (point->x <= g->map->width -1)
		{
			if (point->x == 0 || point->x == g->map->width - 1 || \
				point->y == 0 || point->y == g->map->height - 1)
				choose_tile_sprite(g, point);
			else
				set_tile(g, g->map->sprite_void->sprite, point, \
				PATH_SPRITE_VOID);
			point->x++;
		}
		point->y++;
	}
}

static void	set_ui_tile(t_game *game, t_sprite *sprite)
{
	t_point	*ui_point;

	ui_point = init_point();
	ui_point->z = Z_DEFAULT_UI;
	set_tile(game, sprite, ui_point, PATH_SPRITE_UI);
}

void	set_map(t_game *g)
{
	t_point	*point;

	set_ui_tile(g, g->map->sprite_ui);
	set_background_tiles(g);
	point = init_point();
	point->z = Z_DEFAULT;
	while (point->y < g->map->height)
	{
		point->x = 0;
		while (point->x < g->map->width)
		{
			if (g->map->map_data[point->y][point->x] == WAll)
				set_tile(g, g->map->sprite_wall, point, PATH_SPRITE_WALL);
			else if (g->map->map_data[point->y][point->x] == EXIT)
				set_tile(g, g->map->sprite_exit, point, PATH_SPRITE_EXIT);
			else if (g->map->map_data[point->y][point->x] == COLLECT)
				set_tile(g, g->map->sprite_collect, point, PATH_SPRITE_COLLECT);
			point->x++;
		}
		point->y++;
	}
}
