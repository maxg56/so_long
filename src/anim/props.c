/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   props.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	prop_add(t_game *g, int x, int y)
{
	t_data_map	*l;
	t_prop		*p;

	l = cur_lvl(g);
	p = &l->props[l->nb_props++];
	*p = (t_prop){x, y, 0, (x * 7 + y * 13) * 0.37, 0.0, FALSE};
	p->inst = mlx_image_to_window(get_mlx(), l->collect_img, 0, 0);
	if (p->inst < 0)
		exit_error("Failed to put collectible to window");
	mlx_set_instance_depth(&l->collect_img->instances[p->inst],
		depth_of(x, y, 0));
}

/* un champignon par 'C' de la carte */
void	props_init(t_game *g)
{
	t_data_map	*l;
	int			x;
	int			y;

	l = cur_lvl(g);
	l->props = ft_arnalloc(sizeof(t_prop) * (l->map->total_collect + 1));
	l->collect_img = texture_scaled(g->assets.collect, 2);
	if (!l->props || !l->collect_img)
		exit_error("Failed to create collectibles");
	l->nb_props = 0;
	y = -1;
	while (++y < l->map->height)
	{
		x = -1;
		while (++x < l->map->width)
			if (l->map->map_data[y][x] == COLLECT)
				prop_add(g, x, y);
	}
	props_update(g, 0.0);
}

/* flottement sinusoidal, puis envol rapide une fois ramasse */
static void	prop_place(t_game *g, t_prop *p)
{
	mlx_instance_t	*in;
	double			off;

	in = &cur_lvl(g)->collect_img->instances[p->inst];
	off = sin(p->phase) * 4.0;
	if (p->taken)
		off = -(p->pop / POP_TIME) * 40.0;
	in->x = g->cam.ox + (int)iso_wx(p->x, p->y) - 66;
	in->y = g->cam.oy + (int)(iso_wy(p->x, p->y) + off) - 84;
	if (p->taken && p->pop >= POP_TIME)
		in->enabled = FALSE;
}

void	props_update(t_game *g, double dt)
{
	t_data_map	*l;
	t_prop		*p;
	int			i;

	l = cur_lvl(g);
	i = -1;
	while (++i < l->nb_props)
	{
		p = &l->props[i];
		if (p->taken && p->pop >= POP_TIME)
			continue ;
		p->phase += dt * 3.0;
		if (p->taken)
			p->pop += dt;
		prop_place(g, p);
	}
}

void	prop_take(t_game *g, int x, int y)
{
	t_data_map	*l;
	int			i;

	l = cur_lvl(g);
	i = -1;
	while (++i < l->nb_props)
		if (l->props[i].x == x && l->props[i].y == y && !l->props[i].taken)
			l->props[i].taken = TRUE;
	l->map->map_data[y][x] = VOID;
	l->map->info->collectibles--;
	hud_refresh(g);
	if (l->map->info->collectibles == 0)
		exit_open(g);
}
