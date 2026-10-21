/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* copie la frame courante de la feuille de sprites (miroir si besoin) */
static void	blit_frame(t_game *g, t_player *p)
{
	mlx_texture_t	*s;
	uint8_t			*src;
	uint8_t			*dst;
	uint32_t		y;
	uint32_t		x;

	s = g->assets.sheet;
	y = -1;
	while (++y < FRAME_SZ)
	{
		src = &s->pixels[(((p->anim.row * FRAME_SZ) + y) * s->width
				+ p->anim.frame * FRAME_SZ) * 4];
		dst = &p->img->pixels[y * FRAME_SZ * 4];
		if (!p->anim.flip)
		{
			ft_memcpy(dst, src, FRAME_SZ * 4);
			continue ;
		}
		x = -1;
		while (++x < FRAME_SZ)
			ft_memcpy(&dst[x * 4], &src[(FRAME_SZ - 1 - x) * 4], 4);
	}
	p->anim.dirty = FALSE;
}

void	player_init_sprite(t_game *g)
{
	t_player	*p;

	p = cur_lvl(g)->player;
	if (g->assets.sheet->width < FRAME_SZ * SHEET_COLS
		|| g->assets.sheet->height < FRAME_SZ * (ROW_RUN + 1))
		exit_error("Player sprite sheet too small");
	p->img = mlx_new_image(get_mlx(), FRAME_SZ, FRAME_SZ);
	if (!p->img || mlx_image_to_window(get_mlx(), p->img, 0, 0) < 0)
		exit_error("Failed to create player image");
	p->anim = (t_anim){0.0, 0, ROW_IDLE, FALSE, TRUE};
	blit_frame(g, p);
	player_place(g);
}

/* idle a l'arret, course pendant un deplacement */
void	player_anim_update(t_game *g, double dt)
{
	t_player	*p;
	int			row;

	p = cur_lvl(g)->player;
	row = ROW_IDLE;
	if (p->tw.active)
		row = ROW_RUN;
	if (row != p->anim.row)
	{
		p->anim.row = row;
		p->anim.frame = 0;
		p->anim.timer = 0.0;
		p->anim.dirty = TRUE;
	}
	p->anim.timer += dt;
	while (p->anim.timer >= FRAME_TIME)
	{
		p->anim.timer -= FRAME_TIME;
		p->anim.frame = (p->anim.frame + 1) % SHEET_COLS;
		p->anim.dirty = TRUE;
	}
	if (p->anim.dirty)
		blit_frame(g, p);
}

/* position ecran + petit saut pendant le deplacement + profondeur */
void	player_place(t_game *g)
{
	t_player		*p;
	mlx_instance_t	*in;
	double			hop;
	int				cx;
	int				cy;

	p = cur_lvl(g)->player;
	in = &p->img->instances[0];
	hop = 0.0;
	if (p->tw.active)
		hop = sin(p->tw.t * M_PI) * 6.0;
	in->x = g->cam.ox + (int)iso_wx(p->fx, p->fy) - ANCHOR_X;
	in->y = g->cam.oy + (int)(iso_wy(p->fx, p->fy) - hop) - ANCHOR_Y;
	cx = p->position->x;
	cy = p->position->y;
	if (p->tw.active && p->tw.dx + p->tw.dy < 0)
	{
		cx -= p->tw.dx;
		cy -= p->tw.dy;
	}
	mlx_set_instance_depth(in, depth_of(cx, cy, 1));
}
