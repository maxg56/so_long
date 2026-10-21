/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:06:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/31 17:09:18 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data_map	*init_data_map(void)
{
	t_data_map	*game;

	game = ft_arnalloc(sizeof(t_data_map));
	if (!game)
		return (NULL);
	ft_bzero(game, sizeof(t_data_map));
	game->map = init_map();
	if (!game->map)
		exit_error("Map initialization failed");
	game->player = init_player(0, 0);
	if (!game->player)
		exit_error("Player initialization failed");
	return (game);
}

t_flag	*init_flag(void)
{
	t_flag	*flag;

	flag = ft_arnalloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->bnse = FALSE;
	flag->r = FALSE;
	flag->d = FALSE;
	flag->count = 1;
	flag->ndmap = 0;
	return (flag);
}

t_game	*init_game(void)
{
	t_game	*g;

	g = ft_arnalloc(sizeof(t_game));
	if (!g)
		return (NULL);
	ft_bzero(g, sizeof(t_game));
	g->flag = init_flag();
	if (!g->flag)
		return (NULL);
	g->state = ST_PLAY;
	g->game_satu = FALSE;
	return (g);
}
