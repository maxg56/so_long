/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_queue(t_game *g, int dx, int dy)
{
	cur_lvl(g)->player->queued_x = dx;
	cur_lvl(g)->player->queued_y = dy;
}

/* direction tenue au clavier (deplacement continu) */
static t_bool	held_dir(int *d)
{
	mlx_t	*m;

	m = get_mlx();
	d[0] = 0;
	d[1] = 0;
	if (mlx_is_key_down(m, MLX_KEY_W) || mlx_is_key_down(m, MLX_KEY_UP))
		d[1] = -1;
	else if (mlx_is_key_down(m, MLX_KEY_S) || mlx_is_key_down(m, MLX_KEY_DOWN))
		d[1] = 1;
	else if (mlx_is_key_down(m, MLX_KEY_A) || mlx_is_key_down(m, MLX_KEY_LEFT))
		d[0] = -1;
	else if (mlx_is_key_down(m, MLX_KEY_D)
		|| mlx_is_key_down(m, MLX_KEY_RIGHT))
		d[0] = 1;
	return (d[0] || d[1]);
}

static void	try_move(t_game *g, int dx, int dy)
{
	t_player	*p;
	t_bool		flip;

	p = cur_lvl(g)->player;
	flip = p->anim.flip;
	if (dx - dy != 0)
		flip = (dx - dy < 0);
	if (flip != p->anim.flip)
		p->anim = (t_anim){p->anim.timer, p->anim.frame, p->anim.row,
			flip, TRUE};
	if (cur_lvl(g)->map->map_data[p->position->y + dy][p->position->x + dx]
		== WAll)
		return ;
	p->position->x += dx;
	p->position->y += dy;
	p->move_count++;
	ft_printf("moves: %d\n", p->move_count);
	p->tw = (t_tween){TRUE, 0.0, dx, dy};
	hud_refresh(g);
}

/* fin de deplacement : ramassage, puis sortie si tout est ramasse */
static void	on_arrive(t_game *g)
{
	t_data_map	*l;
	t_player	*p;
	char		c;

	l = cur_lvl(g);
	p = l->player;
	c = l->map->map_data[p->position->y][p->position->x];
	if (c == COLLECT)
		prop_take(g, p->position->x, p->position->y);
	if (c == EXIT && l->map->info->collectibles == 0)
	{
		if (g->i_game == g->flag->ndmap - 1)
			set_state(g, ST_VICTORY);
		else
			set_state(g, ST_LEVEL_DONE);
	}
}

void	player_update(t_game *g, double dt)
{
	t_player	*p;
	double		e;
	int			d[2];

	p = cur_lvl(g)->player;
	if (p->tw.active)
	{
		p->tw.t += dt / MOVE_TIME;
		if (p->tw.t >= 1.0)
			p->tw.active = FALSE;
		e = 1.0 - (1.0 - fmin(p->tw.t, 1.0)) * (1.0 - fmin(p->tw.t, 1.0));
		p->fx = p->position->x - p->tw.dx * (1.0 - e);
		p->fy = p->position->y - p->tw.dy * (1.0 - e);
		if (!p->tw.active)
			on_arrive(g);
		return ;
	}
	d[0] = p->queued_x;
	d[1] = p->queued_y;
	p->queued_x = 0;
	p->queued_y = 0;
	if (d[0] || d[1] || held_dir(d))
		try_move(g, d[0], d[1]);
}
