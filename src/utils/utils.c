/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_texture_t	*load_texture(char *path)
{
	mlx_texture_t	*t;

	t = mlx_load_png(path);
	if (!t)
		exit_error(ft_strjoin("Failed to load texture: ", path));
	return (t);
}

void	load_assets(t_game *g)
{
	g->assets.sheet = load_texture(PATH_SHEET);
	g->assets.grass = load_texture(PATH_GRASS);
	g->assets.stone = load_texture(PATH_STONE);
	g->assets.collect = load_texture(PATH_COLLECT);
}

void	free_assets(t_game *g)
{
	if (g->assets.sheet)
		mlx_delete_texture(g->assets.sheet);
	if (g->assets.grass)
		mlx_delete_texture(g->assets.grass);
	if (g->assets.stone)
		mlx_delete_texture(g->assets.stone);
	if (g->assets.collect)
		mlx_delete_texture(g->assets.collect);
	g->assets = (t_assets){NULL, NULL, NULL, NULL};
}

/* agrandit une texture d'un facteur entier k (plus proche voisin) */
mlx_image_t	*texture_scaled(mlx_texture_t *t, uint32_t k)
{
	mlx_image_t	*img;
	uint32_t	x;
	uint32_t	y;

	img = mlx_new_image(get_mlx(), t->width * k, t->height * k);
	if (!img)
		exit_error("Failed to scale texture");
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			ft_memcpy(&img->pixels[(y * img->width + x) * 4],
				&t->pixels[((y / k) * t->width + x / k) * 4], 4);
			x++;
		}
		y++;
	}
	return (img);
}
