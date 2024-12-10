/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:06:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 02:07:51 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*init_window(char *title, int width, int height)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->width = width;
	window->height = height;
	window->title = title;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, width, height, title);
	return (window);
}
