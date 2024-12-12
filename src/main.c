/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 16:48:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void ft_hook(void * game)
{
	t_game *g = (t_game *)game;
	if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_ESCAPE))
		exit_game(g);
	if (g->player->health_points == 0)
		exit_game(g);
	if (g->map->info->has_exit == TRUE && g->map->info->collectibles == 0)
		exit_game(g);
	

}

void key_hook(mlx_key_data_t keydata, void *param)
{
    

    t_game *g = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
    	if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_ESCAPE))
    	    exit_game(g);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_UP) || mlx_is_key_down(g->window->mlx_instance, MLX_KEY_W))
			move_player(g, 0, -1); 
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_DOWN) || mlx_is_key_down(g->window->mlx_instance, MLX_KEY_S))
			move_player(g, 0, 1);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_LEFT) || mlx_is_key_down(g->window->mlx_instance, MLX_KEY_A))
			move_player(g, -1, 0);
		if (mlx_is_key_down(g->window->mlx_instance, MLX_KEY_RIGHT) || mlx_is_key_down(g->window->mlx_instance, MLX_KEY_D))
			move_player(g, 1, 0);
	}
	
}



int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_game();
	if (!game)
		return (error("Malloc failed", NULL), EXIT_FAILURE);
	game->map = init_map();
	parse_input(argc, argv, game);
	game->map->info->has_exit = FALSE;
	game->window = init_window("so_long", \
				(game->map->width * TILE_SIZE ), \
				(game->map->height * TILE_SIZE ));
	if (!game->window)
		return (error("Malloc failed", game), EXIT_FAILURE);
	game->player->sprite = open_image(PATH_SPRITE_PLAYER, game->window->mlx_instance);
	mlx_image_to_window(game->window->mlx_instance, game->player->sprite, 0, 0);
	printf("2");
	set_map(game);
	set_coordinates(game);
	mlx_loop_hook(game->window->mlx_instance, ft_hook, game);
	mlx_key_hook(game->window->mlx_instance, key_hook, game);
	mlx_close_hook(game->window->mlx_instance, exit_game, game);
	mlx_loop(game->window->mlx_instance);
	return (EXIT_SUCCESS);
}
