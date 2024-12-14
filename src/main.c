/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 03:41:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *game)
{
	t_init_game	*gi;
	t_game		*g;

	gi = (t_init_game *)game;
	g = gi->game[gi->i_game];
	if (g->game_satu == FALSE)
	{
		sleep(1);
		if (gi->i_game == gi->flag->ndmap - 1)
			exit_game(gi);
		else
			closed_game(gi);
	}
	if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_ESCAPE))
		exit_game(g);
	if (g->player->health_points == 0)
		exit_game(g);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_init_game	*ig;
	t_game		*g;

	ig = (t_init_game *)param;
	g = ig->game[ig->i_game];
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) && \
		g->game_satu)
	{
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_ESCAPE))
			exit_game(ig);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_UP) || \
			mlx_is_key_down(g->window->mlx_instance, MLX_KEY_W))
			move_player(g, 0, -1);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_DOWN) || \
			mlx_is_key_down(g->window->mlx_instance, MLX_KEY_S))
			move_player(g, 0, 1);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_LEFT) || \
			mlx_is_key_down(g->window->mlx_instance, MLX_KEY_A))
			move_player(g, -1, 0);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_RIGHT) || \
			mlx_is_key_down(g->window->mlx_instance, MLX_KEY_D))
			move_player(g, 1, 0);
	}

}

void	lood_game(t_init_game *ig)
{
	t_game		*game;

	game = ig->game[ig->i_game];
	if (ig->window == NULL)
	{
		game->window = init_window("so_long", \
				(game->map->width * TILE_SIZE), \
				(game->map->height * TILE_SIZE));
		if (!game->window)
			exit_game(game);
		ig->window = game->window;
	}
	else
	{
		game->window = ig->window;
		mlx_set_window_size(game->window->mlx_instance, \
			(game->map->width * TILE_SIZE), \
			(game->map->height * TILE_SIZE));
	}
	set_player(game);
	set_map(game);

}

int	main(int argc, char **argv)
{
	t_init_game	*intt_game;
	int			i;

	intt_game = init_init_game();
	if (!intt_game)
		return (error("Malloc failed", NULL), EXIT_FAILURE);
	parse_flag(argc, argv, intt_game);
	i = -1;
	while (++i < intt_game->flag->ndmap)
	{
		if (!open_and_check_map(intt_game->game[i], intt_game->paths[i]))
			return (exit_error(NULL, intt_game), EXIT_FAILURE);
	}
	lood_game(intt_game);
	mlx_loop_hook(intt_game->window->mlx_instance, ft_hook, intt_game);
	mlx_key_hook(intt_game->window->mlx_instance, key_hook, intt_game);
	mlx_close_hook(intt_game->window->mlx_instance, exit_game, intt_game);
	mlx_loop(intt_game->window->mlx_instance);
}
