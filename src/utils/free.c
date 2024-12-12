/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:25:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 00:46:50 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (map->map != NULL)
		free_tab((char **) map->map);
	free(map->info);
	free(map);
}

void	free_window(t_window *window)
{
	mlx_close_window(window->mlx);
	if (window->mlx)
			free(window->mlx);
	free(window);
}

void free_player(t_player *player)
{
	if (player->point)
		free(player->point);
	free(player);
}

void	free_game(t_game *game)
{
	if (game->maps)
		free_map(game->maps);
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


