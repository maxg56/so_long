/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 05:42:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 05:43:39 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
