/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_tase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 07:05:05 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 02:04:22 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_t	*cont_tatse(t_game *s_game, t_point *point)
{
	t_t	*t;

	t = ft_arnalloc(sizeof(t_t));
	t->w = FALSE;
	t->e = FALSE;
	t->s = FALSE;
	t->n = FALSE;
	if (point->x == 0)
		t->w = TRUE;
	if (point->x == s_game->map->width - 1)
		t->e = TRUE;
	if (point->y == 0)
		t->n = TRUE;
	if (point->y == s_game->map->height - 1)
		t->s = TRUE;
	return (t);
}

void	_choose_tatse(t_game *game, t_point *point, t_sprite_map *sm, t_t *t)
{
	if (t->w && t->s)
		set_tlse(game, sm->sprite_sw, point, PATH_SPRITE_VOID_SW);
	else if (t->e && t->n)
		set_tlse(game, sm->sprite_ne, point, PATH_SPRITE_VOID_NE);
	else if (t->e && t->s)
		set_tlse(game, sm->sprite_se, point, PATH_SPRITE_VOID_SE);
	else if (t->n && t->s)
		set_tlse(game, sm->sprite_ns, point, PATH_SPRITE_VOID_NS);
	else if (t->w && t->e)
		set_tlse(game, sm->sprite_ews, point, PATH_SPRITE_VOID_EW);
	else if (t->w)
		set_tlse(game, sm->sprite_w, point, PATH_SPRITE_VOID_W);
	else if (t->e)
		set_tlse(game, sm->sprite_e, point, PATH_SPRITE_VOID_E);
	else if (t->n)
		set_tlse(game, sm->sprite_n, point, PATH_SPRITE_VOID_N);
	else if (t->s)
		set_tlse(game, sm->sprite_s, point, PATH_SPRITE_VOID_S);
	else
		set_tlse(game, game->map->sprite_void->sprite, point, PATH_SPRITE_VOID);
}

void	choose_tatse(t_game *game, t_point *point)
{
	t_t				*t;
	t_sprite_map	*sm;

	sm = game->map->sprite_void;
	t = cont_tatse(game, point);
	if (t->w && t->e && t->n && t->s)
		set_tlse(game, sm->sprite_news, point, PATH_SPRITE_VOID_NEWS);
	else if (t->w && t->e && t->n)
		set_tlse(game, sm->sprite_new, point, PATH_SPRITE_VOID_NEW);
	else if (t->w && t->e && t->s)
		set_tlse(game, sm->sprite_sew, point, PATH_SPRITE_VOID_SEW);
	else if (t->w && t->n && t->s)
		set_tlse(game, sm->sprite_wns, point, PATH_SPRITE_VOID_WNS);
	else if (t->e && t->n && t->s)
		set_tlse(game, sm->sprite_ens, point, PATH_SPRITE_VOID_ENS);
	else if (t->w && t->n)
		set_tlse(game, sm->sprite_nw, point, PATH_SPRITE_VOID_NW);
	else
		_choose_tatse(game, point, sm, t);
}
