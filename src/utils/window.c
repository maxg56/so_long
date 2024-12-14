/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:06:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 03:43:16 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*init_window(char *title, int width, int height)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->width = width;
	window->height = height;
	window->title = title;
	window->mlx_instance = mlx_init(width, height, title, true);
	if (!window->mlx_instance)
		return (free(window), puts(mlx_strerror(mlx_errno)), NULL);
	return (window);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->window = NULL;
	game->map = init_map();
	game->game_satu = TRUE;
	game->player = init_player(0, 0);
	if (!game->player)
		return (free(game), NULL);
	game->sprites_id = init_int_list();
	if (!game->sprites_id)
		return (free(game), NULL);
	return (game);
}

t_flag	*init_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->bnse = FALSE;
	flag->r = FALSE;
	flag->g = FALSE;
	flag->count = 1;
	flag->ndmap = 0;
	return (flag);
}

t_init_game	*init_init_game(void)
{
	t_init_game	*g;

	g = malloc(sizeof(t_init_game));
	if (!g)
		return (NULL);
	g->flag = init_flag();
	g->paths = NULL;
	g->game = NULL;
	g->i_game = 0;
	g->window = NULL;
	return (g);
}
