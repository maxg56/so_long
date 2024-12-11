/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:48:58 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 02:08:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		exit_game(game);
		exit(0);
	}
	return (0);
}

// main.c
const int direction_offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(int argc, char** argv)
{
	t_game	*game;
	t_bool	check;

	game = init_game();
	if (!game)
		return (error("Malloc failed", NULL), EXIT_FAILURE);
	game->maps = init_map();
	check = parse_input(argc, argv, game);

	game->window = init_window("so_long",
				game->maps->width * 32,
				game->maps->height * 32
				);
	if (!game->window || !game->window->mlx)
		return (error("Malloc failed", game), EXIT_FAILURE);
		
	if (!(image = mlx_new_image(game->window->mlx, 34, 34)))
	{
		mlx_close_window(game->window->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(game->window->mlx, image, 0, 0) == -1)
	{
		mlx_close_window(game->window->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(game->window->mlx, ft_randomize, game->window->mlx);
	mlx_loop_hook(game->window->mlx, ft_hook, game->window->mlx);

	mlx_loop(game->window->mlx);
	mlx_terminate(game->window->mlx);
	return (EXIT_SUCCESS);
}
/*
int main(int argc, char **argv)
{
	t_game	*game;
	t_bool	check;

	game = init_game();
	if (!game)
		return (error("Malloc failed", NULL), EXIT_FAILURE);
	game->maps = init_map();
	check = parse_input(argc, argv, game);

	game->window = init_window("so_long",
				game->maps->width * 32,
				game->maps->height * 32);
	if (!game->window)
		return (error("Malloc failed", game), EXIT_FAILURE);


	mlx_hook(game->window->win, 2, 0, key_hook, game);
	mlx_loop(game->window->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
*/
