/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:06:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 12:07:52 by max_dev          ###   ########.fr       */
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
	window->mlx_instance = mlx_init(width, height, title, true);
	if (!window->mlx_instance)
		return (free(window), puts(mlx_strerror(mlx_errno)), NULL);
	return (window);
}


