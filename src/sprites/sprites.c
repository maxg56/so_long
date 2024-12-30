/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:36:23 by acabon            #+#    #+#             */
/*   Updated: 2024/12/19 18:14:21 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"



/*** falaise complete ***/
// t_data_sprite *test_falaise;
// t_coord coord_test_falaise;
// // coord_test = init_coord(0, 0, 256, 512);
// coord_test_falaise = init_coord(0, 0, 193, 257);// 193, 257 pour le bloque
// generate_sheet("./assets/img/Tilemap_Elevation.png", &test_falaise, coord_test_falaise);
// create_instance(test_falaise, 0, 600);
// // put_sprite(test);

/*** terrain complete ***/
// t_data_sprite *test_grass;
// t_coord coord_test_grass;
// coord_test_grass = init_coord(0, 0, 193, 193);// 640, 256 pour le bloque // largeur, hauteur
// generate_sheet("./assets/img/Tilemap_Flat.png", &test_grass, coord_test_grass);
// create_instance(test_grass, 0, 600);
// // put_sprite(test);

/*** cases ***/
// t_data_sprite *test_grass2;
// t_coord coord_test_grass2;
// // les cases feront 130 de hauteur et largeur ?
// coord_test_grass2 = init_coord(30, 30, 130, 130);// 640, 256 pour le bloque // largeur, hauteur
// generate_sheet("./assets/img/Tilemap_Flat.png", &test_grass2, coord_test_grass2);
// create_instance(test_grass2, 100, 200);
// create_instance(test_grass2, 100, 329);
// create_instance(test_grass2, 229, 329);
	

int generate_sheet(char *path, t_data_sprite **new_sprite_data, t_coord coord) // ajouter x et y a la fonction ?
{
	t_data_sprite *sprite_data;

	(*new_sprite_data) = malloc(sizeof(t_data_sprite));
	if ((*new_sprite_data) == NULL)
		return (EXIT_FAILURE);

	sprite_data = *new_sprite_data;
	if (!(sprite_data->texture_png = mlx_load_png(path)))
	{
		// tout free ?
		return(EXIT_FAILURE);
	}

	sprite_data->sheet_height = sprite_data->texture_png->height;
	sprite_data->sheet_width = sprite_data->texture_png->width;
	sprite_data->coord = coord;
	sprite_data->nb_instances = 0;
	sprite_data->animate = 0;

	// if (!(sprite_data->img = mlx_texture_to_image(get_mlx(), sprite_data->texture_png)))
	// ft_printf("test4\n");
	// ft_printf("bvcx = %d %d\n", sprite_data->coord.width, sprite_data->coord.height);
	if (!(sprite_data->img = mlx_new_image(get_mlx(), sprite_data->coord.width, sprite_data->coord.height)))
	{
		mlx_delete_texture(sprite_data->texture_png);
		return(EXIT_FAILURE);
	}
	return (0);
}


t_coord init_coord(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
		t_coord coord;

		coord.x = x;
		coord.y = y;
		coord.width = width;
		coord.height = height;
		return (coord);
}

void put_sprite(void* param) // passer en parametre les coord
{
	t_data_sprite *data_sprite;
	uint32_t y;
	uint32_t x;
	uint32_t color;

	data_sprite = param;

	y = data_sprite->coord.y;
	while (y < (data_sprite->coord.height + data_sprite->coord.y - 1))
	{
		x = data_sprite->coord.x;
		while (x < (data_sprite->coord.width + data_sprite->coord.x - 1))
		{

			color = ft_pixel( 
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4], 
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4 + 1],
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4 + 2],
					data_sprite->texture_png->pixels[((data_sprite->sheet_width * y) + x) * 4 + 3]
			);
			mlx_put_pixel(data_sprite->img, x - data_sprite->coord.x, y - data_sprite->coord.y, color);

			x++;
		}
		y++;
	}
}