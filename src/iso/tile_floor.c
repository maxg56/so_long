/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Coordonnees (u, v) dans [0, 1] d'un pixel du losange : retourne FALSE
 * si le pixel est hors du losange.
 */
t_bool	diamond_uv(int px, int py, double *uv)
{
	double	a;
	double	b;

	a = (px + 0.5 - TILE_W / 2.0) / (TILE_W / 2.0);
	b = (py + 0.5) / (TILE_H / 2.0);
	uv[0] = (b + a) / 2.0;
	uv[1] = (b - a) / 2.0;
	return (uv[0] >= 0.0 && uv[0] < 1.0 && uv[1] >= 0.0 && uv[1] < 1.0);
}

static void	floor_px(t_game *g, mlx_image_t *img, int *p, double shade)
{
	double	uv[2];
	uint8_t	c[4];
	t_rect	r;

	if (!diamond_uv(p[0], p[1], uv))
		return ;
	r = (t_rect){24, 24, 140, 140};
	tex_sample(g->assets.grass, r, uv, c);
	if (uv[0] < 0.04 || uv[1] < 0.04 || uv[0] > 0.96 || uv[1] > 0.96)
		shade *= 0.78;
	px_shade(c, shade);
	c[3] = 255;
	px_blend(img, p[0], p[1], c);
}

/* tuile de sol : herbe projetee dans un losange, bord assombri */
mlx_image_t	*build_floor(t_game *g, double shade)
{
	mlx_image_t	*img;
	int			p[2];

	img = mlx_new_image(get_mlx(), TILE_W, TILE_H);
	if (!img)
		exit_error("Failed to create floor image");
	p[1] = -1;
	while (++p[1] < TILE_H)
	{
		p[0] = -1;
		while (++p[0] < TILE_W)
			floor_px(g, img, p, shade);
	}
	return (img);
}
