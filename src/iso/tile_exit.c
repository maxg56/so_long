/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* anneau au sol : pierre grise si ferme, violet lumineux si ouvert */
static void	ring_px(mlx_image_t *img, int *p, t_bool open, double glow)
{
	double	dx;
	double	dy;
	double	d;
	uint8_t	c[4];

	dx = (p[0] - TILE_W / 2.0) / (TILE_W * 0.36);
	dy = (p[1] - (EXIT_H + TILE_H / 2.0)) / (TILE_H * 0.36);
	d = sqrt(dx * dx + dy * dy);
	if (d > 1.0)
		return ;
	if (d > 0.72 && !open)
		set_rgba(c, 0x7B8794, 255);
	else if (d > 0.72)
		set_rgba(c, 0xA070F0, 255);
	else if (!open)
		set_rgba(c, 0x1F2430, 230);
	else
		set_rgba(c, 0x7C3AED, (uint8_t)(150 + 100 * glow * (1.0 - d)));
	if (d > 0.72)
		px_shade(c, 1.15 - (d - 0.72));
	if (open)
		px_shade(c, 0.8 + 0.4 * glow);
	px_blend(img, p[0], p[1], c);
}

/* colonne de lumiere au dessus du portail ouvert */
static void	beam(mlx_image_t *img, double glow)
{
	int		x;
	int		y;
	double	fx;
	double	fy;
	uint8_t	c[4];

	y = -1;
	while (++y < EXIT_H + TILE_H / 2)
	{
		x = -1;
		fy = (double)y / (EXIT_H + TILE_H / 2.0);
		while (++x < TILE_W)
		{
			fx = fabs(x - TILE_W / 2.0) / (TILE_W * 0.26);
			if (fx >= 1.0)
				continue ;
			set_rgba(c, 0xE9D5FF, (uint8_t)(110 * glow * fy * (1.0 - fx)));
			px_blend(img, x, y, c);
		}
	}
}

/* trois etincelles qui tournent et montent selon la frame */
static void	sparks(mlx_image_t *img, int frame)
{
	int		j;
	int		k;
	double	a;
	int		pos[2];
	uint8_t	c[4];

	set_rgba(c, 0xFFFFFF, 255);
	j = -1;
	while (++j < 3)
	{
		a = frame * (2 * M_PI / EXIT_FRAMES) + j * (2 * M_PI / 3);
		pos[0] = TILE_W / 2 + (int)(cos(a) * TILE_W * 0.24);
		pos[1] = EXIT_H + TILE_H / 2 + (int)(sin(a) * TILE_H * 0.24)
			- ((frame * 9 + j * 20) % (EXIT_H - 8));
		k = -2;
		while (++k < 2)
		{
			px_blend(img, pos[0] + k, pos[1], c);
			px_blend(img, pos[0], pos[1] + k, c);
		}
	}
}

/* image du portail de sortie ; frame sert a l'animation quand ouvert */
mlx_image_t	*build_exit(int frame, t_bool open)
{
	mlx_image_t	*img;
	int			p[2];
	double		glow;

	img = mlx_new_image(get_mlx(), TILE_W, TILE_H + EXIT_H);
	if (!img)
		exit_error("Failed to create exit image");
	glow = 0.75 + 0.25 * sin(frame * (2 * M_PI / EXIT_FRAMES));
	p[1] = EXIT_H - 1;
	while (++p[1] < (int)img->height)
	{
		p[0] = -1;
		while (++p[0] < TILE_W)
			ring_px(img, p, open, glow);
	}
	if (open)
	{
		beam(img, glow);
		sparks(img, frame);
	}
	return (img);
}
