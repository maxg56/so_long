/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_panel(mlx_image_t *img)
{
	uint8_t		c[4];
	uint32_t	x;
	uint32_t	y;

	set_rgba(c, 0x1E1B2E, 235);
	img_fill(img, c);
	set_rgba(c, 0xA070F0, 255);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (x < 3 || y < 3 || x >= img->width - 3 || y >= img->height - 3)
				ft_memcpy(&img->pixels[(y * img->width + x) * 4], c, 4);
			x++;
		}
		y++;
	}
}

static mlx_image_t	*ov_image(t_game *g, int w, int h, int z)
{
	mlx_image_t	*img;

	img = mlx_new_image(get_mlx(), w, h);
	if (!img || mlx_image_to_window(get_mlx(), img, 0, 0) < 0)
		exit_error("Failed to create overlay");
	mlx_set_instance_depth(&img->instances[0], g->z_ui + z);
	return (img);
}

/* fond assombri + panneau + lignes de texte (tableau termine par NULL) */
void	overlay_show(t_game *g, char **lines)
{
	t_overlay	*o;
	int			i;

	overlay_hide(g);
	o = &g->ov;
	o->dim = ov_image(g, g->win_w, g->win_h, 1);
	o->panel = ov_image(g, PANEL_W, PANEL_H, 2);
	o->panel->instances[0].x = (g->win_w - PANEL_W) / 2;
	draw_panel(o->panel);
	i = 0;
	while (lines[i] && i < OV_LINES)
	{
		o->lines[i] = mlx_put_string(get_mlx(), lines[i],
				(g->win_w - (int)ft_strlen(lines[i]) * 10) / 2, 0);
		if (!o->lines[i])
			exit_error("Failed to draw overlay text");
		mlx_set_instance_depth(&o->lines[i]->instances[0], g->z_ui + 3);
		i++;
	}
	o->nb_lines = i;
	o->fade = 0.0;
	o->visible = TRUE;
	overlay_update(g, 0.0);
}

void	overlay_hide(t_game *g)
{
	t_overlay	*o;
	int			i;

	o = &g->ov;
	if (o->dim)
		mlx_delete_image(get_mlx(), o->dim);
	if (o->panel)
		mlx_delete_image(get_mlx(), o->panel);
	i = -1;
	while (++i < o->nb_lines)
		mlx_delete_image(get_mlx(), o->lines[i]);
	o->dim = NULL;
	o->panel = NULL;
	o->nb_lines = 0;
	o->visible = FALSE;
}

/* fondu du fond + glissement du panneau depuis le haut */
void	overlay_update(t_game *g, double dt)
{
	t_overlay	*o;
	uint8_t		c[4];
	double		e;
	int			off;
	int			i;

	o = &g->ov;
	if (!o->visible || o->fade >= 1.0)
		return ;
	o->fade = fmin(1.0, o->fade + dt / FADE_TIME);
	set_rgba(c, 0x05030A, (uint8_t)(170 * o->fade));
	img_fill(o->dim, c);
	e = 1.0 - pow(1.0 - o->fade, 3.0);
	off = (int)((1.0 - e) * -80.0) + (g->win_h - PANEL_H) / 2;
	o->panel->instances[0].y = off;
	i = -1;
	while (++i < o->nb_lines)
		o->lines[i]->instances[0].y = off + 36 + i * 36;
}
