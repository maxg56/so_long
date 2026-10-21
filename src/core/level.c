/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* remet la carte et le joueur dans leur etat de depart */
void	reset_level_data(t_data_map *l)
{
	l->map->map_data = mapcpy(l->map->map_orig, l->map->height);
	if (!l->map->map_data)
		exit_error("Malloc failed");
	l->map->info->collectibles = l->map->total_collect;
	l->player->position->x = l->player->spawn.x;
	l->player->position->y = l->player->spawn.y;
	l->player->move_count = 0;
	l->player->tw = (t_tween){FALSE, 0.0, 0, 0};
	l->player->queued_x = 0;
	l->player->queued_y = 0;
}

void	load_level(t_game *g)
{
	t_data_map	*l;

	l = cur_lvl(g);
	reserve_depth(g);
	l->player->fx = l->player->position->x;
	l->player->fy = l->player->position->y;
	camera_snap(g);
	render_map(g);
	exit_init(g);
	props_init(g);
	player_init_sprite(g);
	hud_refresh(g);
	g->game_satu = TRUE;
	set_state(g, ST_PLAY);
}

void	unload_level(t_game *g)
{
	t_data_map	*l;
	int			i;

	l = cur_lvl(g);
	overlay_hide(g);
	hud_delete(g);
	i = -1;
	while (++i < l->nb_imgs)
		mlx_delete_image(get_mlx(), l->imgs[i]);
	l->nb_imgs = 0;
	if (l->collect_img)
		mlx_delete_image(get_mlx(), l->collect_img);
	if (l->player->img)
		mlx_delete_image(get_mlx(), l->player->img);
	l->collect_img = NULL;
	l->player->img = NULL;
	g->game_satu = FALSE;
}
