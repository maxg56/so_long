/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:56:23 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 02:58:53 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	uload_sprite(t_game *game, t_sprite *s)
{
	supr_id_int_list(&game->sprites_id, s->id);
	if (s->sprite)
		mlx_delete_image(game->window->mlx_instance, s->sprite);
}

void	uload_sprite_map(t_game *game, t_sprite_map *sm)
{
	uload_sprite(game, sm->sprite);
	uload_sprite(game, sm->sprite_e);
	uload_sprite(game, sm->sprite_ens);
	uload_sprite(game, sm->sprite_ews);
	uload_sprite(game, sm->sprite_w);
	uload_sprite(game, sm->sprite_wns);
	uload_sprite(game, sm->sprite_n);
	uload_sprite(game, sm->sprite_ns);
	uload_sprite(game, sm->sprite_nw);
	uload_sprite(game, sm->sprite_ne);
	uload_sprite(game, sm->sprite_new);
	uload_sprite(game, sm->sprite_news);
	uload_sprite(game, sm->sprite_s);
	uload_sprite(game, sm->sprite_sw);
	uload_sprite(game, sm->sprite_se);
	uload_sprite(game, sm->sprite_sew);
}

void	uload_map(t_game *game)
{
	uload_sprite(game, game->map->sprite_exit);
	uload_sprite(game, game->map->sprite_collect);
	uload_sprite(game, game->map->sprite_wall);
	uload_sprite(game, game->map->sprite_wotre);
	uload_sprite_map(game, game->map->sprite_void);
}

void	uload_player(t_game *game)
{
	uload_sprite(game, game->player->sprite);
}

void	unload_add(t_game *game)
{
	uload_map(game);
	uload_player(game);
}
