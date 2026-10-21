/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* garde une trace des images "fixes" du niveau (camera + dechargement) */
mlx_image_t	*track_img(t_data_map *l, mlx_image_t *img)
{
	if (l->nb_imgs >= MAX_LVL_IMGS)
		exit_error("Too many level images");
	l->imgs[l->nb_imgs++] = img;
	return (img);
}

/* pose une instance dont le coin haut-gauche est relatif a la case (x, y) */
void	put_tile(t_game *g, mlx_image_t *img, t_point *p, int lift)
{
	int32_t	sx;
	int32_t	sy;
	int32_t	i;

	sx = g->cam.ox + (int)iso_wx(p->x, p->y) - TILE_W / 2;
	sy = g->cam.oy + (int)iso_wy(p->x, p->y) - TILE_H / 2 - lift;
	i = mlx_image_to_window(get_mlx(), img, sx, sy);
	if (i < 0)
		exit_error("Failed to put tile to window");
	mlx_set_instance_depth(&img->instances[i], p->z);
}

static void	place_cell(t_game *g, mlx_image_t **tiles, int x, int y)
{
	t_point	p;
	char	c;

	c = cur_lvl(g)->map->map_data[y][x];
	p = (t_point){x, y, depth_of(x, y, -1)};
	if (c == WAll)
	{
		p.z = depth_of(x, y, 0);
		if (x == cur_lvl(g)->map->width - 1
			|| y == cur_lvl(g)->map->height - 1)
			put_tile(g, tiles[3], &p, LEDGE_H);
		else
			put_tile(g, tiles[2], &p, WALL_H);
		return ;
	}
	put_tile(g, tiles[(x + y) % 2], &p, 0);
}

/*
 * Construit les tuiles iso du niveau puis pose sol et murs. Les murs du
 * bord avant (bas-gauche / bas-droite) sont des rebords bas pour ne pas
 * masquer la derniere rangee de cases.
 */
void	render_map(t_game *g)
{
	t_data_map	*l;
	mlx_image_t	*tiles[4];
	int			x;
	int			y;

	l = cur_lvl(g);
	tiles[0] = track_img(l, build_floor(g, 1.0));
	tiles[1] = track_img(l, build_floor(g, 0.9));
	tiles[2] = track_img(l, build_wall(g, WALL_H));
	tiles[3] = track_img(l, build_wall(g, LEDGE_H));
	y = -1;
	while (++y < l->map->height)
	{
		x = -1;
		while (++x < l->map->width)
			place_cell(g, tiles, x, y);
	}
}
