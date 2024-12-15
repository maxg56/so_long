/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_tase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 07:05:05 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 21:11:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_tile_flags	*initialize_tile_flags(t_game *game, t_point *point)
{
	t_tile_flags	*tile_flags;

	tile_flags = ft_arnalloc(sizeof(tile_flags));
	tile_flags->w = (point->x == 0);
	tile_flags->e = (point->x == game->map->width - 1);
	tile_flags->n = (point->y == 0);
	tile_flags->s = (point->y == game->map->height - 1);
	return (tile_flags);
}

void	choose_tile_sprite(t_game *game, t_point *point)
{
	t_tile_flags	*t;
	t_sprite_map	*sm;

	sm = game->map->sprite_void;
	t = initialize_tile_flags(game, point);
	if (t->w && t->s)
		set_tile(game, sm->sprite_sw, point, PATH_SPRITE_VOID_SW);
	else if (t->e && t->n)
		set_tile(game, sm->sprite_ne, point, PATH_SPRITE_VOID_NE);
	else if (t->e && t->s)
		set_tile(game, sm->sprite_se, point, PATH_SPRITE_VOID_SE);
	else if (t->n && t->s)
		set_tile(game, sm->sprite_ns, point, PATH_SPRITE_VOID_NS);
	else if (t->w && t->e)
		set_tile(game, sm->sprite_ew, point, PATH_SPRITE_VOID_EW);
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
