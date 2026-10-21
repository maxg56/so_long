/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_exit(t_data_map *l)
{
	int	x;
	int	y;

	y = -1;
	while (++y < l->map->height)
	{
		x = -1;
		while (++x < l->map->width)
		{
			if (l->map->map_data[y][x] == EXIT)
			{
				l->exit.x = x;
				l->exit.y = y;
				return ;
			}
		}
	}
}

/* portail ferme + frames d'animation du portail ouvert (cachees) */
void	exit_init(t_game *g)
{
	t_data_map	*l;
	t_point		p;
	int			k;

	l = cur_lvl(g);
	find_exit(l);
	p = (t_point){l->exit.x, l->exit.y, depth_of(l->exit.x, l->exit.y, 0)};
	l->exit.closed = track_img(l, build_exit(0, FALSE));
	put_tile(g, l->exit.closed, &p, EXIT_H);
	k = -1;
	while (++k < EXIT_FRAMES)
	{
		l->exit.open[k] = track_img(l, build_exit(k, TRUE));
		put_tile(g, l->exit.open[k], &p, EXIT_H);
		l->exit.open[k]->instances[0].enabled = FALSE;
	}
	l->exit.is_open = FALSE;
	l->exit.frame = 0;
	l->exit.timer = 0.0;
	if (l->map->info->collectibles == 0)
		exit_open(g);
}

void	exit_open(t_game *g)
{
	t_exit	*e;

	e = &cur_lvl(g)->exit;
	if (e->is_open)
		return ;
	e->is_open = TRUE;
	e->closed->instances[0].enabled = FALSE;
	e->open[e->frame]->instances[0].enabled = TRUE;
}

void	exit_update(t_game *g, double dt)
{
	t_exit	*e;

	e = &cur_lvl(g)->exit;
	if (!e->is_open)
		return ;
	e->timer += dt;
	while (e->timer >= EXIT_FRAME_TIME)
	{
		e->timer -= EXIT_FRAME_TIME;
		e->open[e->frame]->instances[0].enabled = FALSE;
		e->frame = (e->frame + 1) % EXIT_FRAMES;
		e->open[e->frame]->instances[0].enabled = TRUE;
	}
}
