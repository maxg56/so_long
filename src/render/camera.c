/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * b = {min monde, max monde, min ecran, max ecran}.
 * Centre la carte si elle tient a l'ecran, sinon suit le point focus
 * en restant dans les limites de la carte.
 */
static double	cam_axis(double *b, double focus)
{
	double	o;

	if (b[1] - b[0] <= b[3] - b[2])
		return ((b[2] + b[3]) / 2.0 - (b[0] + b[1]) / 2.0);
	o = (b[2] + b[3]) / 2.0 - focus;
	if (o > b[2] - b[0])
		o = b[2] - b[0];
	if (o < b[3] - b[1])
		o = b[3] - b[1];
	return (o);
}

static void	cam_target(t_game *g, double *tx, double *ty)
{
	t_data_map	*l;
	double		b[4];
	double		f[2];

	l = cur_lvl(g);
	f[0] = iso_wx(l->player->fx, l->player->fy);
	f[1] = iso_wy(l->player->fx, l->player->fy) - TILE_H;
	b[0] = -l->map->height * (TILE_W / 2.0);
	b[1] = l->map->width * (TILE_W / 2.0);
	b[2] = MARGIN;
	b[3] = g->win_w - MARGIN;
	*tx = cam_axis(b, f[0]);
	b[0] = -WALL_H;
	b[1] = (l->map->width + l->map->height) * (TILE_H / 2.0);
	b[2] = HUD_H + TOP_ROOM;
	b[3] = g->win_h - MARGIN;
	*ty = cam_axis(b, f[1]);
}

/* decale toutes les instances fixes du niveau */
static void	shift_static(t_game *g, int dx, int dy)
{
	t_data_map	*l;
	int			i;
	size_t		k;

	l = cur_lvl(g);
	i = -1;
	while (++i < l->nb_imgs)
	{
		k = 0;
		while (k < l->imgs[i]->count)
		{
			l->imgs[i]->instances[k].x += dx;
			l->imgs[i]->instances[k].y += dy;
			k++;
		}
	}
}

void	camera_snap(t_game *g)
{
	cam_target(g, &g->cam.x, &g->cam.y);
	g->cam.ox = (int)lround(g->cam.x);
	g->cam.oy = (int)lround(g->cam.y);
	g->cam.ready = TRUE;
}

/* suivi amorti de la camera */
void	camera_update(t_game *g, double dt)
{
	double	t[2];
	double	k;
	int		nx;
	int		ny;

	cam_target(g, &t[0], &t[1]);
	k = dt * CAM_SPEED;
	if (k > 1.0)
		k = 1.0;
	g->cam.x += (t[0] - g->cam.x) * k;
	g->cam.y += (t[1] - g->cam.y) * k;
	nx = (int)lround(g->cam.x);
	ny = (int)lround(g->cam.y);
	if (nx == g->cam.ox && ny == g->cam.oy)
		return ;
	shift_static(g, nx - g->cam.ox, ny - g->cam.oy);
	g->cam.ox = nx;
	g->cam.oy = ny;
}
