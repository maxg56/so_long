/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:34:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 08:21:09 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	set_map(t_game *game)
{
	int	x;
	int	y;
	int	tx_i;

	tx_i = 0;
	y = 0;
	while (y < game->maps->height)
	{
		x = 0;
		while (x < game->maps->width)
		{
			if (game->maps->map[y][x] == MUR )
			{
				if (tx_i == 0)
				{
					game->maps->sprat_void = open_image("Water.png", game->window->mlx);
				}
				mlx_image_to_window(game->window->mlx, game->maps->sprat_void, x *64, y*64);
				set_z(game->maps->sprat_void,tx_i,1);
				tx_i++;
				
			}
			x++;
		}
		y++;
	}
}

