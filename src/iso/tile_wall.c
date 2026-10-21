/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wall_top(t_game *g, mlx_image_t *img, int px, int py)
{
	double	uv[2];
	uint8_t	c[4];

	if (!diamond_uv(px, py, uv))
		return ;
	tex_sample(g->assets.stone, (t_rect){20, 12, 150, 100}, uv, c);
	if (uv[0] < 0.03 || uv[1] < 0.03 || uv[0] > 0.97 || uv[1] > 0.97)
		px_shade(c, 1.25);
	c[3] = 255;
	px_blend(img, px, py, c);
}

/* face gauche (left = TRUE) ou droite du cube, cisaillee en iso */
static void	wall_side(t_game *g, mlx_image_t *img, int *p, t_bool left)
{
	double	top;
	double	uv[2];
	uint8_t	c[4];
	int		h;

	if (left)
		top = TILE_H / 2.0 + p[0] * ((double)TILE_H / TILE_W);
	else
		top = TILE_H - (p[0] - TILE_W / 2.0) * ((double)TILE_H / TILE_W);
	h = img->height - TILE_H;
	if (p[1] < top || p[1] >= top + h)
		return ;
	uv[0] = (p[0] % (TILE_W / 2)) / (TILE_W / 2.0);
	uv[1] = (p[1] - top) / h;
	tex_sample(g->assets.stone, (t_rect){8, 140, 176, 96}, uv, c);
	if (left)
		px_shade(c, 0.80);
	else
		px_shade(c, 0.58);
	if (uv[1] > 0.92)
		px_shade(c, 0.6);
	c[3] = 255;
	px_blend(img, p[0], p[1], c);
}

/* bloc de pierre de hauteur height : dessus en losange + deux faces */
mlx_image_t	*build_wall(t_game *g, int height)
{
	mlx_image_t	*img;
	int			p[2];

	img = mlx_new_image(get_mlx(), TILE_W, TILE_H + height);
	if (!img)
		exit_error("Failed to create wall image");
	p[1] = -1;
	while (++p[1] < (int)img->height)
	{
		p[0] = -1;
		while (++p[0] < TILE_W)
		{
			wall_side(g, img, p, p[0] < TILE_W / 2);
			wall_top(g, img, p[0], p[1]);
		}
	}
	return (img);
}
