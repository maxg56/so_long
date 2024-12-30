/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cara.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:17 by acabon            #+#    #+#             */
/*   Updated: 2024/12/30 16:04:04 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int init_sprite_main_cara(t_data_sprite **data_sprite)
{
	(*data_sprite) = malloc(sizeof(t_data_sprite));
	if (*data_sprite == NULL)
		return (EXIT_FAILURE);
	(*data_sprite)->sprite_width = 192;
	(*data_sprite)->sprite_height = 192;
	(*data_sprite)->sheet_width = 1152;
	(*data_sprite)->sheet_height = 1536;
	(*data_sprite)->stats = 0;
	(*data_sprite)->animate = 1;
	(*data_sprite)->main_cara = 1;
	return (0);
}
int main_cara_to_window(t_data_sprite *sprite_data)
{
	if (mlx_image_to_window(get_mlx(), sprite_data->img,
		WIDTH / 2 - (sprite_data->sprite_width / 2),
		HEIGHT / 2 - (sprite_data->sprite_height / 2)) == -1)
	{
		return(1);
	}
	return (0);
}

//faire un generate animate cara ?
int generate_main_cara(t_data_sprite **sprite_data)
{
	t_data_sprite *sprite_main_data;

	if (init_sprite_main_cara(sprite_data))
		return (EXIT_FAILURE);
	sprite_main_data = *sprite_data;

	if (!(sprite_main_data->texture_png = mlx_load_png("./assets/img/Warrior_Purple.png")))
	{
		// tout free ?
		return(EXIT_FAILURE);
	}
	if (!(sprite_main_data->img = mlx_new_image(get_mlx(), sprite_main_data->sprite_width, sprite_main_data->sprite_height)))
	{
		mlx_delete_texture(sprite_main_data->texture_png);
		return(EXIT_FAILURE);
	}
	// if (mlx_image_to_window(get_mlx(), sprite_main_data->img, 0, 0) == -1)
	// if (mlx_image_to_window(get_mlx(), sprite_main_data->img,
	// 	WIDTH / 2 - (sprite_main_data->sprite_width / 2),
	// 	HEIGHT / 2 - (sprite_main_data->sprite_height / 2)) == -1)
	// {
	// 	return(EXIT_FAILURE);
	// }
	return (0);
}
