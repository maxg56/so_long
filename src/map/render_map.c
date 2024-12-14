/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 06:57:22 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_bak_boms(t_game *game)
{
	t_point	*point;

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
	free(point);
}

void	set_bak(t_game *g)
{
	t_point	*point;

	point = init_point();
	point->z = Z_BACKGROUND;
	point->y = 1;
	while (point->y < g->map->height - 1)
	{
		point->x = 1;
		while (point->x < g->map->width -1)
		{
			if (point->x == 1 || point->x == g->map->width - 2 || \
				point->y == 1 || point->y == g->map->height - 2)
				choose_tatse(g, point);
			else
				set_tlse(g, g->map->sprite_void->sprite, point, \
				PATH_SPRITE_VOID);
			point->x++;
		}
		point->y++;
	}
	free(point);
}

void	set_ui(t_game *g, t_sprite *sprite)
{
	t_point		*p;

	p = init_point();
	p->z = Z_DEFAULT_UI;
	set_tlse(g, sprite, p, PATH_SPRITE_UI);
}

void	set_map(t_game *g)
{
	t_point	*point;

	set_ui(g, g->map->sprite_ui);
	set_bak_boms(g);
	point = init_point();
	point->z = Z_DEFAULT;
	while (point->y < g->map->height)
	{
		point->x = 0;
		while (point->x < g->map->width)
		{
			if (g->map->map_data[point->y][point->x] == WAll)
				set_tlse(g, g->map->sprite_wall, point, PATH_SPRITE_WALL);
			else if (g->map->map_data[point->y][point->x] == EXIT)
				set_tlse(g, g->map->sprite_exit, point, PATH_SPRITE_EXIT);
			else if (g->map->map_data[point->y][point->x] == COLLECT)
				set_tlse(g, g->map->sprite_collect, point, PATH_SPRITE_COLLECT);
			point->x++;
		}
		point->y++;
	}
	free(point);
}
