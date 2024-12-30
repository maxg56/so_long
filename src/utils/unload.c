/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:56:23 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 16:07:25 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	uload_sprite(t_data_map *game, t_sprite *s)
{
	supr_id_int_list(&game->sprites_id, s->id);
	if (s->sprite)
		mlx_delete_image(game->window->mlx_instance, s->sprite);
}

static void	uload_sprite_map(t_data_map *game, t_sprite_map *sm)
{
	uload_sprite(game, sm->sprite);
	uload_sprite(game, sm->sprite_e);
	uload_sprite(game, sm->sprite_w);
	uload_sprite(game, sm->sprite_n);
	uload_sprite(game, sm->sprite_ns);
	uload_sprite(game, sm->sprite_nw);
	uload_sprite(game, sm->sprite_ne);
	uload_sprite(game, sm->sprite_s);
	uload_sprite(game, sm->sprite_sw);
	uload_sprite(game, sm->sprite_se);
	uload_sprite(game, sm->sprite_ew);
}

static void	uload_map(t_data_map *game)
{
	uload_sprite(game, game->map->sprite_exit);
	uload_sprite(game, game->map->sprite_collect);
	uload_sprite(game, game->map->sprite_wall);
	uload_sprite(game, game->map->sprite_wotre);
	uload_sprite(game, game->map->sprite_ui);
	uload_sprite(game, game->player->sprite);
	uload_sprite_map(game, game->map->sprite_void);
}

static void	uload_ui(t_data_map *game)
{
	if (game->sprite_move)
		mlx_delete_image(game->window->mlx_instance, game->sprite_move);
	if (game->sprite_pv)
		mlx_delete_image(game->window->mlx_instance, game->sprite_pv);
}

void	unload_add(t_data_map *game)
{
	uload_map(game);
	uload_ui(game);
}
