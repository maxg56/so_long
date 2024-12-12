/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erore.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:19:14 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 16:57:39 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message, t_game *game)
{
	ft_dprintf(2, RED"Error:\n%s\n"DEF_COLOR, message);
	if (game)
		free_game(game);
	exit(1);
}

void exit_game( void *param)
{
	t_game *game ;
	
	game = (t_game *)param;
	mlx_close_window(game->window->mlx_instance);
	mlx_terminate(game->window->mlx_instance);
	free_game(game);
	exit(0);
}

