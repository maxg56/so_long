/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:25:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 06:52:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprite_map(t_sprite_map *map)
{
	free(map->sprite);
	free(map->sprite_e);
	free(map->sprite_ens);
	free(map->sprite_ews);
	free(map->sprite_w);
	free(map->sprite_wns);
	free(map->sprite_n);
	free(map->sprite_ns);
	free(map->sprite_nw);
	free(map->sprite_ne);
	free(map->sprite_new);
	free(map->sprite_news);
	free(map->sprite_s);
	free(map->sprite_sw);
	free(map->sprite_se);
	free(map->sprite_sew);
	free(map);
}

void	free_map(t_map *map)
{
	if (map->map_data != NULL)
		free_tab(map->map_data);
	free(map->info);
	free_sprite_map(map->sprite_void);
	free(map->sprite_wall);
	free(map->sprite_exit);
	free(map->sprite_collect);
	free(map->sprite_wotre);
	free(map);
}

void	free_player(t_player *player)
{
	if (player->position)
		free(player->position);
	free(player->sprite);
	free(player);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->player)
		free_player(game->player);
	if (game->window)
		//free(game->window);
	if (game->sprites_id)
		free_int_list(game->sprites_id);
	free(game);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
