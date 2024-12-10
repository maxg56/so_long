/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 10:48:34 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->window->mlx, game->window->win);
		free_game(game);
		exit(0);
	}
	return (0);	
}

int main(int argc, char **argv)
{
	t_game	*game;
	char	**map;
	t_bool	check;

	map = NULL;
	game = init_game();
	game->maps = init_map();
	check = parse_input(argc, argv, game);
	game->window = init_window("so_long",
								game->maps->width *32,
								game->maps->height * 32
								);	
	mlx_hook(game->window->win, 2, 0, key_hook, game);
	mlx_hook(game->window->win, 2, 0, key_hook, game);
	mlx_loop(game->window->mlx);
	free_game(game);
	return (0);
}
