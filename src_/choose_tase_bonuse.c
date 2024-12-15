/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_tase_bonuse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:08:26 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 20:57:45 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static void	set_bak_boms(t_game *game)
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
			choose_tile_sprite(game, point);
			point->x++;
		}
		point->y++;
	}
}


static tile_flags	*initialize_tile_flags(t_game *s_game, t_point *point)
{
	t_tile_flags	*t;

	t = ft_arnalloc(sizeof(tile_flags));
	t->w = FALSE;
	t->e = FALSE;
	t->s = FALSE;
	t->n = FALSE;
	if (point->x > 0 && s_game->map->map_data[point->y][point->x - 1] == WAll)
		t->w = TRUE;
	if (point->x < s_game->map->width - 1 && s_game->map->map_data[point->y] \
	[point->x + 1] == WAll)
		t->e = TRUE;
	if (point->y > 0 && s_game->map->map_data[point->y - 1][point->x] == WAll)
		t->n = TRUE;
	if (point->y < s_game->map->height - 1 && \
		s_game->map->map_data[point->y + 1][point->x] == WAll)
		t->s = TRUE;
	return (t);
}

void	_choose_tile_sprite(t_game *game, t_point *point, t_sprite_map *sm, t_tile_flags *t)
{
	if (t->w && t->s)
		set_tile(game, sm->sprite_sw, point, PATH_SPRITE_VOID_SW);
	else if (t->e && t->n)
		set_tile(game, sm->sprite_ne, point, PATH_SPRITE_VOID_NE);
	else if (t->e && t->s)
		set_tile(game, sm->sprite_se, point, PATH_SPRITE_VOID_SE);
	else if (t->n && t->s)
		set_tile(game, sm->sprite_ns, point, PATH_SPRITE_VOID_NS);
	else if (t->w && t->e)
		set_tile(game, sm->sprite_ews, point, PATH_SPRITE_VOID_EW);
	else if (t->w)
		set_tile(game, sm->sprite_w, point, PATH_SPRITE_VOID_W);
	else if (t->e)
		set_tile(game, sm->sprite_e, point, PATH_SPRITE_VOID_E);
	else if (t->n)
		set_tile(game, sm->sprite_n, point, PATH_SPRITE_VOID_N);
	else if (t->s)
		set_tile(game, sm->sprite_s, point, PATH_SPRITE_VOID_S);
	else
		set_tile(game, game->map->sprite_void->sprite, point, PATH_SPRITE_VOID);
}

void	choose_tile_sprite_buse(t_game *game, t_point *point)
{
	tile_flags				*t;
	t_sprite_map	*sm;

	sm = game->map->sprite_void;
	t = initialize_tile_flags(game, point);
	if (t->w && t->e && t->n && t->s)
		set_tile(game, sm->sprite_news, point, PATH_SPRITE_VOID_NEWS);
	else if (t->w && t->e && t->n)
		set_tile(game, sm->sprite_new, point, PATH_SPRITE_VOID_NEW);
	else if (t->w && t->e && t->s)
		set_tile(game, sm->sprite_sew, point, PATH_SPRITE_VOID_SEW);
	else if (t->w && t->n && t->s)
		set_tile(game, sm->sprite_wns, point, PATH_SPRITE_VOID_WNS);
	else if (t->e && t->n && t->s)
		set_tile(game, sm->sprite_ens, point, PATH_SPRITE_VOID_ENS);
	else if (t->w && t->n)
		set_tile(game, sm->sprite_nw, point, PATH_SPRITE_VOID_NW);
	else
		_choose_tile_sprite(game, point, sm, t);
}
