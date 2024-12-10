/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 17:43:34 by maxence          ###   ########.fr       */
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
    t_game *game;
    t_bool check;

    game = init_game();
    if (!game)
        return (1);

    game->maps = init_map();
    if (!game->maps)
    {
        free_game(game);
        return (1);
    }

    check = parse_input(argc, argv, game);
    if (!check)
    {
        free_game(game);
        return (1);
    }

    game->window = init_window("so_long",
                               game->maps->width * 32,
                               game->maps->height * 32);
    if (!game->window)
    {
        free_game(game);
        return (1);
    }

    mlx_hook(game->window->win, 2, 0, key_hook, game);
    mlx_loop(game->window->mlx);
    free_game(game);
    return (0);
}

