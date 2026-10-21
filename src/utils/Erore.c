/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erore.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message)
{
	ft_dprintf(2, RED"Error\n%s\n"DEF_COLOR, message);
	ft_arna_free();
	exit(1);
}

void	exit_game(t_game *g)
{
	free_assets(g);
	if (get_mlx())
	{
		mlx_close_window(get_mlx());
		mlx_terminate(get_mlx());
	}
	ft_arna_free();
	exit(0);
}
