/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:37:42 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/31 16:51:31 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_sprite_image(char *path, mlx_t *mlx)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_error("Error: texture not initialized");
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		exit_error("Error: image or instances not initialized");
	return (image);
}

void	set_player_coordinates(t_data_map *game )
{
	int	tmp;

	tmp = game->player->position->x * TILE_SIZE;
	game->player->sprite->sprite->instances[0].x = tmp;
	tmp = game->player->position->y * TILE_SIZE;
	game->player->sprite->sprite->instances[0].y = tmp;
	game->player->sprite->sprite->instances[0].z = Z_DEFAULT_PLAYER;
}

mlx_t	*get_mlx(void)
{
	static mlx_t*	mlx = NULL;

	if (!mlx)
		mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	return (mlx);
}
