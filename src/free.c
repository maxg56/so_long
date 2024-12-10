/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:25:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 09:56:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	while (map->height--)
	{
		free((void *)map->map[map->height]);
	}
	free_map_info(map->info);
	free(map->map);
	free(map);
}

void	free_game(t_game *game)
{
	free_map(game->maps);
	free(game->player);
	free(game->window);
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
void	free_map_info(t_map_info *val)
{
	free(val);
}
