/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_animates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:01 by acabon            #+#    #+#             */
/*   Updated: 2024/12/30 15:24:43 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// int generate_animate_sprite(t_data_sprite **sprite_data)
// {
// 	t_data_sprite *sprite_main_data;

// 	if (init_sprite_main_cara(sprite_data)) // faire une fonction qui init un sprit
// 		return (EXIT_FAILURE);
// 	sprite_main_data = *sprite_data;

// 	if (!(sprite_main_data->texture_png = mlx_load_png("./assets/img/Warrior_Purple.png")))
// 	{
// 		// tout free ?
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(sprite_main_data->img = mlx_new_image(get_mlx(), sprite_main_data->sprite_width, sprite_main_data->sprite_height)))
// 	{
// 		mlx_delete_texture(sprite_main_data->texture_png);
// 		return(EXIT_FAILURE);
// 	}
// 	// if (mlx_image_to_window(get_mlx(), sprite_main_data->img, 0, 0) == -1)
// 	// {
// 	// 	return(EXIT_FAILURE);
// 	// }
// 	return (0);
// }

// faire des tests
void ft_animate_sprite(void* param)
{
	static uint32_t frame = 0;
	t_data_sprite *data_sprite;
	data_sprite = param;
	uint32_t y;
	uint32_t x;
	uint32_t color;

	y = data_sprite->sprite_height * data_sprite->stats; // states
	while (y < (data_sprite->sprite_height * ((uint32_t)1 + data_sprite->stats)))
	{
		x = data_sprite->sprite_width * (frame / FRAME_ANIMATION);
		while (x < (data_sprite->sprite_width * ((uint32_t)1 + (frame / FRAME_ANIMATION))))
		{
			color = ft_pixel(
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4], // R
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4 + 1], // G
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4 + 2], // B
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4 + 3]  // A
				);
			mlx_put_pixel(data_sprite->img,
				x - data_sprite->sprite_width * (frame / FRAME_ANIMATION),
				y - data_sprite->sprite_height * data_sprite->stats, color);
			x++;
		}
		y++;
	}
	if (frame == FRAME_ANIMATION * 6)
		frame = 0;
	else
		frame++;
	 data_sprite->stats = 0;
}
