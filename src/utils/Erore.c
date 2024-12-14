/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erore.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:19:14 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 05:41:35 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message, t_init_game *game)
{
	if (message != NULL)
		ft_dprintf(2, RED"Error:\n%s\n"DEF_COLOR, message);
	if (game)
		free_init_game(game);
	exit(1);
}

void	error(char *message, t_game *game)
{
	ft_dprintf(2, RED"Error:\n%s\n"DEF_COLOR, message);
	if (game)
		free_game(game);
}

void	closed_game(t_init_game	*g)
{
	unload_add(g->game[g->i_game]);
	free_game(g->game[g->i_game]);
	g->i_game++;
	lood_game(g);
}

void	exit_game( void *param)
{
	t_init_game	*game ;

	game = (t_init_game *)param;
	mlx_close_window(game->window->mlx_instance);
	mlx_terminate(game->window->mlx_instance);
	free_init_game(game);
	exit(0);
}
