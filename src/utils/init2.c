/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:06:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 16:24:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*init_window(char *title, int width, int height)
{
	t_window	*window;

	window = ft_arnalloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->width = width;
	window->height = height;
	window->title = title;
	window->mlx_instance = mlx_init(width, height, title, true);
	if (!window->mlx_instance)
		return (puts(mlx_strerror(mlx_errno)), NULL);
	return (window);
}

t_data_map	*init_game(void)
{
	t_data_map	*game;

	game = ft_arnalloc(sizeof(t_data_map));
	if (!game)
		return (NULL);
	game->window = ft_arnalloc(sizeof(t_window));
	game->map = init_map();
	if (!game->map)
		exit_error("Map initialization failed");
	game->game_satu = TRUE;
	game->player = init_player(0, 0);
	if (!game->player)
		return (NULL);
	game->sprites_id = init_int_list();
	if (!game->sprites_id)
		return (NULL);
	game->sprite_move = NULL;
	game->sprite_pv = NULL;
	game->fps = 30;
	game->enemy = NULL;
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

t_game	*init_init_game(void)
{
	t_game	*g;

	g = ft_arnalloc(sizeof(t_game));
	if (!g)
		return (NULL);
	g->flag = init_flag();
	g->paths = NULL;
	g->game = NULL;
	g->i_game = 0;
	g->window = NULL;
	g->game_satu = FALSE;
	return (g);
}
