/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:25:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 03:36:50 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (map->map_data != NULL)
		free_tab(map->map_data);
	free(map->info);
	free(map->sprite_void);
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
		free(game->window);
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

void	free_init_game(t_init_game *game)
{
	int	i;

	i = 0;
	if (game->i_game == game->flag->ndmap - 1)
		free_game(game->game[game->i_game]);
	else
	{
		while (i < game->flag->ndmap)
		{
			free_game(game->game[i]);
			i++;
		}
	}
	free(game->game);
	free(game->flag);
	free_tab(game->paths);
	free(game);
}
