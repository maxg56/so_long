/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_tase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:08:26 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 01:12:33 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static t_t *cont_tatse(t_game *s_game, t_point *point)
{
	t_t *t;
	
	t = malloc(sizeof(t_t));
	t->w = FALSE;
	t->e = FALSE;
	t->s= FALSE;
	t->n = FALSE;
	if (point->x > 0 && s_game->map->map_data[point->y][point->x - 1] == WAll)
		t->w = TRUE;
	if (point->x < s_game->map->width - 1 && s_game->map->map_data[point->y][point->x + 1] == WAll)
		t->e = TRUE;
	if (point->y > 0 && s_game->map->map_data[point->y - 1][point->x] == WAll)
		t->n = TRUE;
	if (point->y < s_game->map->height - 1 && s_game->map->map_data[point->y + 1][point->x] == WAll)
		t->s = TRUE;
	return (t);
}

void choose_tatse(t_game *game, t_point *point)
{
	t_t *t;
	
	t = cont_tatse(game, point);
	if (t->w && t->e && t->n && t->s) 
		set_tlse(game, game->map->sprite_void->sprite_news, point, PATH_SPRITE_VOID_NEWS);
	else if (t->w && t->e && t->n)
		set_tlse(game, game->map->sprite_void->sprite_new, point, PATH_SPRITE_VOID_NEW);
	else if (t->w && t->e && t->s)
		set_tlse(game, game->map->sprite_void->sprite_sew, point, PATH_SPRITE_VOID_SEW);
	else if (t->w && t->n && t->s)
		set_tlse(game, game->map->sprite_void->sprite_wns, point, PATH_SPRITE_VOID_WNS);
	else if (t->e && t->n && t->s)
		set_tlse(game, game->map->sprite_void->sprite_ens, point, PATH_SPRITE_VOID_ENS);
	else if (t->w && t->n)
		set_tlse(game, game->map->sprite_void->sprite_nw, point, PATH_SPRITE_VOID_NW);
	else if (t->w && t->s)
		set_tlse(game, game->map->sprite_void->sprite_sw, point, PATH_SPRITE_VOID_SW);
	else if (t->e && t->n)
		set_tlse(game, game->map->sprite_void->sprite_ne, point, PATH_SPRITE_VOID_NE);	
	else if (t->e && t->s)
		set_tlse(game, game->map->sprite_void->sprite_se, point, PATH_SPRITE_VOID_SE);
	else if (t->n && t->s)
		set_tlse(game, game->map->sprite_void->sprite_ns, point, PATH_SPRITE_VOID_NS);
	else if (t->w && t->e)
		set_tlse(game, game->map->sprite_void->sprite_ews, point, PATH_SPRITE_VOID_EW);
	else if (t->w)
		set_tlse(game, game->map->sprite_void->sprite_w, point, PATH_SPRITE_VOID_W);
	else if (t->e)
		set_tlse(game, game->map->sprite_void->sprite_e, point, PATH_SPRITE_VOID_E);
	else if (t->n)
		set_tlse(game, game->map->sprite_void->sprite_n, point, PATH_SPRITE_VOID_N);
	else if (t->s)
		set_tlse(game, game->map->sprite_void->sprite_s, point, PATH_SPRITE_VOID_S);
	else
		set_tlse(game, game->map->sprite_void->sprite, point, PATH_SPRITE_VOID);
	free(t);
}
