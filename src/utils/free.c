/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:25:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 00:03:14 by mgendrot         ###   ########.fr       */
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
	if (window->win)
			free(window->mlx);
	free(window);
}

void	free_game(t_game *game)
{
	if (game->maps)
		free_map(game->maps);
	if (game->player)
		free(game->player);
	if (game->window)
		free_window(game->window);
	free(game);
}


void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp->vex);
		free(tmp);
	}
}

