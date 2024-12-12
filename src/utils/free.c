/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:25:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 12:07:50 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (map->map_data != NULL)
		free_tab(map->map_data);
	free(map->info);
	free(map);
}

void	free_window(t_window *window)
{
	mlx_close_window(window->mlx_instance);
	free(window);
}

void free_player(t_player *player)
{
	if (player->position)
		free(player->position);
	free(player);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->player)
		free_player(game->player);
	if (game->window)
		free_window(game->window);
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


