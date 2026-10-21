/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_hook(void *param)
{
	t_game	*g;
	double	dt;

	g = (t_game *)param;
	if (!g->game_satu)
		return ;
	dt = fmin(get_mlx()->delta_time, 0.05);
	if (g->state == ST_PLAY)
		player_update(g, dt);
	player_anim_update(g, dt);
	props_update(g, dt);
	exit_update(g, dt);
	camera_update(g, dt);
	player_place(g);
	overlay_update(g, dt);
}

static void	key_play(t_game *g, keys_t k)
{
	if (k == MLX_KEY_ESCAPE)
		set_state(g, ST_PAUSE);
	else if (k == MLX_KEY_W || k == MLX_KEY_UP)
		player_queue(g, 0, -1);
	else if (k == MLX_KEY_S || k == MLX_KEY_DOWN)
		player_queue(g, 0, 1);
	else if (k == MLX_KEY_A || k == MLX_KEY_LEFT)
		player_queue(g, -1, 0);
	else if (k == MLX_KEY_D || k == MLX_KEY_RIGHT)
		player_queue(g, 1, 0);
}

/* touches des ecrans pause / fin de niveau / game over / victoire */
static void	key_menu(t_game *g, keys_t k)
{
	if (g->state == ST_PAUSE)
	{
		if (k == MLX_KEY_Y || k == MLX_KEY_O || k == MLX_KEY_ENTER)
			set_state(g, ST_GAME_OVER);
		else if (k == MLX_KEY_N || k == MLX_KEY_ESCAPE)
			set_state(g, ST_PLAY);
	}
	else if (g->state == ST_LEVEL_DONE)
	{
		if (k == MLX_KEY_ENTER || k == MLX_KEY_SPACE)
			next_level(g);
		else if (k == MLX_KEY_ESCAPE)
			set_state(g, ST_PAUSE);
	}
	else if (k == MLX_KEY_ESCAPE)
		exit_game(g);
	else if (k == MLX_KEY_R && g->state == ST_GAME_OVER)
		restart_level(g);
	else if (k == MLX_KEY_R)
		restart_all(g);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keydata.action != MLX_PRESS || !g->game_satu)
		return ;
	if (g->state == ST_PLAY)
		key_play(g, keydata.key);
	else
		key_menu(g, keydata.key);
}

void	close_hook(void *param)
{
	exit_game((t_game *)param);
}
