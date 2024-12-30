/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_usils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:35:03 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 16:07:25 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_sprite(t_data_map *game, t_sprite *s, char *path)
{
	int	id;

	if (!s)
		return ;
	s->sprite = load_sprite_image(path, game->window->mlx_instance);
	id = add_int_list(&game->sprites_id, init_int_list());
	s->id = id;
}

static void	set_instance_z(mlx_image_t *sprite, int t, int z)
{
	sprite->instances[t].z = z;
}

t_sprite	*init_sprite(void)
{
	t_sprite	*sprite;

	sprite = ft_arnalloc(sizeof(t_sprite));
	sprite->sprite = NULL;
	sprite->id = -1;
	return (sprite);
}

t_sprite_map	*init_sprite_map(void)
{
	t_sprite_map	*sprite_map;

	sprite_map = ft_arnalloc(sizeof(t_sprite_map));
	sprite_map->sprite = init_sprite();
	sprite_map->sprite_e = init_sprite();
	sprite_map->sprite_w = init_sprite();
	sprite_map->sprite_n = init_sprite();
	sprite_map->sprite_s = init_sprite();
	sprite_map->sprite_ns = init_sprite();
	sprite_map->sprite_nw = init_sprite();
	sprite_map->sprite_ne = init_sprite();
	sprite_map->sprite_sw = init_sprite();
	sprite_map->sprite_se = init_sprite();
	sprite_map->sprite_ew = init_sprite();
	return (sprite_map);
}

void	set_tile(t_data_map *game, t_sprite *sprite, t_point *point, char *path)
{
	t_list_int	*instance_index ;

	if (sprite->id == -1)
		load_sprite(game, sprite, path);
	instance_index = get_int_list(&game->sprites_id, sprite->id);
	mlx_image_to_window(game->window->mlx_instance, sprite->sprite,
		point->x * TILE_SIZE, point->y * TILE_SIZE);
	set_instance_z(sprite->sprite, instance_index->content, point->z);
	instance_index->content++;
}
