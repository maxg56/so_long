/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_t	**mlx_slot(void)
{
	static mlx_t	*mlx = NULL;

	return (&mlx);
}

mlx_t	*get_mlx(void)
{
	return (*mlx_slot());
}

static int	clamp(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

/* taille de fenetre : la plus grande carte, bornee a [MIN, MAX] */
void	open_window(t_game *g)
{
	int	i;
	int	s;
	int	w;
	int	h;

	w = 0;
	h = 0;
	i = -1;
	while (++i < g->flag->ndmap)
	{
		s = g->game[i]->map->width + g->game[i]->map->height;
		if (s * (TILE_W / 2) + 2 * MARGIN > w)
			w = s * (TILE_W / 2) + 2 * MARGIN;
		if (s * (TILE_H / 2) + WALL_H + HUD_H + TOP_ROOM + MARGIN > h)
			h = s * (TILE_H / 2) + WALL_H + HUD_H + TOP_ROOM + MARGIN;
	}
	g->win_w = clamp(w, WIN_MIN_W, WIN_MAX_W);
	g->win_h = clamp(h, WIN_MIN_H, WIN_MAX_H);
	*mlx_slot() = mlx_init(g->win_w, g->win_h, "so_long", false);
	if (!get_mlx())
		exit_error("Failed to init MLX42");
}

/*
 * La projection MLX42 coupe les z hors de [-n, n] (n = nombre total
 * d'instances creees). On ajoute des instances invisibles pour que les
 * profondeurs iso et l'UI restent toujours dans cet intervalle.
 */
void	reserve_depth(t_game *g)
{
	static mlx_image_t	*dummy = NULL;
	t_map				*m;
	int					need;
	int32_t				i;

	m = cur_lvl(g)->map;
	g->z_ui = depth_of(m->width - 1, m->height - 1, 2) + 1;
	need = g->z_ui + 16 - m->width * m->height;
	if (!dummy)
		dummy = mlx_new_image(get_mlx(), 1, 1);
	if (!dummy)
		exit_error("Failed to reserve depth");
	while (need-- > 0)
	{
		i = mlx_image_to_window(get_mlx(), dummy, 0, 0);
		if (i < 0)
			exit_error("Failed to reserve depth");
		dummy->instances[i].enabled = FALSE;
	}
}
