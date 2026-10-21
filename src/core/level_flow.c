/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart_level(t_game *g)
{
	unload_level(g);
	reset_level_data(cur_lvl(g));
	load_level(g);
}

void	next_level(t_game *g)
{
	unload_level(g);
	if (g->i_game + 1 >= g->flag->ndmap)
		exit_game(g);
	g->i_game++;
	load_level(g);
}

void	restart_all(t_game *g)
{
	int	i;

	unload_level(g);
	i = -1;
	while (++i < g->flag->ndmap)
		reset_level_data(g->game[i]);
	g->i_game = 0;
	load_level(g);
}
