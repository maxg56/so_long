/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erore.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:19:14 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/31 16:54:59 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message)
{
	ft_dprintf(2, RED"Error:\n%s\n"DEF_COLOR, message);
	ft_arna_free();
	exit(1);
}

void	error(char *message)
{
	ft_dprintf(2, RED"Error:\n%s\n"DEF_COLOR, message);
}

void	closed_game(t_game	*g)
{
	unload_add(g->game[g->i_game]);
	g->i_game++;
	lood_game(g);
}

void	exit_game( void *param)
{
	t_game	*game ;

	game = (t_game *)param;
	mlx_close_window(get_mlx());
	mlx_terminate(get_mlx());
	ft_arna_free();
	exit(0);
}
