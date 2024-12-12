/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 08:45:57 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


const int direction_offsets[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void ft_hook(void * game)
{
	t_game *g = (t_game *)game;
	if (mlx_is_key_down(g->window->mlx, MLX_KEY_ESCAPE))
		exit_game(g);
	if (g->player->pv == 0)
		exit_game(g);
	if (g->maps->info->exit == TRUE && g->maps->info->collect == 0)
		exit_game(g);
	

}

void key_hook(mlx_key_data_t keydata, void *param)
{
    

    t_game *g = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
    	if (mlx_is_key_down(g->window->mlx, MLX_KEY_ESCAPE))
    	{
    	    exit_game(g); // Ou mlx_close_window(g->window->mlx), mais pas les deux
    	    return;
    	}


    	if (mlx_is_key_down(g->window->mlx, MLX_KEY_UP) || mlx_is_key_down(g->window->mlx, MLX_KEY_W))
    	    move_player(g, 0, -1); // Haut : diminution de la coordonnée Y
    	if (mlx_is_key_down(g->window->mlx, MLX_KEY_DOWN) || mlx_is_key_down(g->window->mlx, MLX_KEY_S))
    	    move_player(g, 0, 1);  // Bas : augmentation de la coordonnée Y
    	if (mlx_is_key_down(g->window->mlx, MLX_KEY_LEFT) || mlx_is_key_down(g->window->mlx, MLX_KEY_A))
    	    move_player(g, -1, 0); // Gauche : diminution de la coordonnée X
    	if (mlx_is_key_down(g->window->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(g->window->mlx, MLX_KEY_D))
    	    move_player(g, 1, 0);
	}
	
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_game();
	if (!game)
		return (error("Malloc failed", NULL), EXIT_FAILURE);
	game->maps = init_map();
	parse_input(argc, argv, game);
	game->maps->info->exit = FALSE;
	game->window = init_window("so_long", \
				(game->maps->width * 64 ), \
				(game->maps->height * 64 ));
	if (!game->window)
		return (error("Malloc failed", game), EXIT_FAILURE);
	game->player->sprite = open_image("09.png", game->window->mlx);
	
	mlx_image_to_window(game->window->mlx, game->player->sprite, 0, 0);
	
	set_map(game);
	set_corde(game);
	mlx_loop_hook(game->window->mlx, ft_hook, game);
	mlx_key_hook(game->window->mlx, key_hook, game);
	mlx_loop(game->window->mlx);
	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}

