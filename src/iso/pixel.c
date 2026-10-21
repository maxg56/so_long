/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_rgba(uint8_t *c, uint32_t hex, uint8_t a)
{
	c[0] = (hex >> 16) & 0xFF;
	c[1] = (hex >> 8) & 0xFF;
	c[2] = hex & 0xFF;
	c[3] = a;
}

/* lit un texel dans la zone r de la texture, uv dans [0, 1] */
void	tex_sample(mlx_texture_t *t, t_rect r, double *uv, uint8_t *out)
{
	int		tx;
	int		ty;
	uint8_t	*src;

	tx = r.x + (int)(uv[0] * r.w);
	ty = r.y + (int)(uv[1] * r.h);
	if (tx >= r.x + r.w)
		tx = r.x + r.w - 1;
	if (ty >= r.y + r.h)
		ty = r.y + r.h - 1;
	src = &t->pixels[(ty * t->width + tx) * 4];
	ft_memcpy(out, src, 4);
}

void	px_shade(uint8_t *c, double s)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (c[i] * s > 255)
			c[i] = 255;
		else
			c[i] = (uint8_t)(c[i] * s);
		i++;
	}
}

/* melange alpha "over" du pixel c sur l'image */
void	px_blend(mlx_image_t *img, int x, int y, uint8_t *c)
{
	uint8_t	*d;
	double	a;
	double	da;
	int		i;

	if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
		return ;
	d = &img->pixels[(y * img->width + x) * 4];
	a = c[3] / 255.0;
	da = d[3] / 255.0 * (1.0 - a);
	if (a + da <= 0.0)
		return ;
	i = -1;
	while (++i < 3)
		d[i] = (uint8_t)((c[i] * a + d[i] * da) / (a + da));
	d[3] = (uint8_t)((a + da) * 255.0);
}

void	img_fill(mlx_image_t *img, uint8_t *c)
{
	uint32_t	i;
	uint32_t	n;

	i = 0;
	n = img->width * img->height;
	while (i < n)
	{
		ft_memcpy(&img->pixels[i * 4], c, 4);
		i++;
	}
}
