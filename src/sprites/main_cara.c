/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cara.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:17 by acabon            #+#    #+#             */
/*   Updated: 2024/12/31 16:36:49 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	init_sprite_main_cara(t_data_sprite **data_sprite)
{
	(*data_sprite) = ft_arnalloc(sizeof(t_data_sprite));
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
	int	x;
	int	y;

	if (!sprite_data || !sprite_data->img)
		return (EXIT_FAILURE);
	x = WIDTH / 2 - (sprite_data->sprite_width / 2);
	y = HEIGHT / 2 - (sprite_data->sprite_height / 2);

	if (mlx_image_to_window(get_mlx(), sprite_data->img, x, y) == -1)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}


//faire un generate animate cara ?
#define ASSET_PATH "./assets/img/Warrior_Purple.png"

int generate_main_character(t_data_sprite **sprite_data)
{
    t_data_sprite	*sprite_main_data;

    if (init_sprite_main_cara(sprite_data))
        return (EXIT_FAILURE);

    sprite_main_data = *sprite_data;
    sprite_main_data->img = load_sprite_image(ASSET_PATH, get_mlx());
	return (EXIT_SUCCESS);
}



