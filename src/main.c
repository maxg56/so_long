/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;

	game = init_game();
	if (!game)
		return (exit_error("Malloc failed"), EXIT_FAILURE);
	parse_flag(argc, argv, game);
	i = -1;
	while (++i < game->flag->ndmap)
	{
		if (!open_and_check_map(game->game[i], game->paths[i]))
			return (EXIT_FAILURE);
	}
	open_window(game);
	load_assets(game);
	load_level(game);
	mlx_loop_hook(get_mlx(), loop_hook, game);
	mlx_key_hook(get_mlx(), key_hook, game);
	mlx_close_hook(get_mlx(), close_hook, game);
	mlx_loop(get_mlx());
	exit_game(game);
	return (EXIT_SUCCESS);
}
