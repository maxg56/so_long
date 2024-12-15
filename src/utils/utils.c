/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:37:42 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 06:50:17 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*open_image(char *path, mlx_t *mlx)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_error("Error: texture not initialized");
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if ( !image)
		exit_error("Error: image or instances not initialized");
	return (image);
}

char	**mapcpy(char **map, int height)
{
	char	**new_map;
	int		i;

	new_map = ft_arnalloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
