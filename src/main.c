/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 16:24:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	finch_game(t_game *game)
{
	game->game_satu = FALSE;
	if (game->i_game == game->flag->ndmap - 1)
		exit_game(game);
	else
		closed_game(game);
}

static void	ft_hook(void *game)
{
	t_data_map		*g;
	t_game	*gi;

	gi = (t_game *)game;
	if (gi->game_satu)
	{
		g = gi->game[gi->i_game];
		if (g->fps == 0)
			g->fps = 30;
		if (g->fps == 10)
		{
			if (g->game_satu == FALSE || g->player->health_points <= 0)
				finch_game(gi);
		}
		g->fps--;
	}
	if (mlx_is_key_down(gi->window->mlx_instance, MLX_KEY_ESCAPE))
		exit_game(g);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*ig;
	t_data_map		*g;

	ig = (t_game *)param;
	if (ig->game_satu)
		g = ig->game[ig->i_game];
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) && \
		ig->game_satu)
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

void	lood_game(t_game *ig)
{
	t_data_map		*game;

	game = ig->game[ig->i_game];
	if (ig->window == NULL)
	{
		ig->window = init_window("so_long", \
				(game->map->width * TILE_SIZE), \
				(game->map->height * TILE_SIZE));
		if (!game->window)
			exit_game(game);
		game->window = ig->window;
	}
	else
	{
		game->window = ig->window;
		mlx_set_window_size(ig->window->mlx_instance, \
			(game->map->width * TILE_SIZE), \
			(game->map->height * TILE_SIZE));
	}
	set_player(game);
	set_move(game);
	set_map(game);
	ig->game_satu = TRUE;
}

int	main(int argc, char **argv)
{
	t_game	*init_game;
	int			i;

	init_game = init_init_game();
	if (!init_game)
		return (exit_error("Malloc failed"), EXIT_FAILURE);
	parse_flag(argc, argv, init_game);
	i = -1;
	while (++i < init_game->flag->ndmap)
	{
		if (!open_and_check_map(init_game->game[i], init_game->paths[i]))
			return (EXIT_FAILURE);
	}
	lood_game(init_game);
	mlx_loop_hook(init_game->window->mlx_instance, ft_hook, init_game);
	mlx_key_hook(init_game->window->mlx_instance, key_hook, init_game);
	mlx_close_hook(init_game->window->mlx_instance, exit_game, init_game);
	mlx_loop(init_game->window->mlx_instance);
}
