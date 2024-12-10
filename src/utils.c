/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:37:42 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 10:45:08 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(void)
{
	t_map	*map_struct;

	map_struct = malloc(sizeof(t_map));
	if (!map_struct)
		return (NULL);
	map_struct->map = NULL;
	map_struct->info = init_val();
	map_struct->width = 0;
	map_struct->height = 0;
	return (map_struct);
}

t_player	*init_player(int x, int y, void *sprite)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos->x = x;
	player->pos->y = y;
	player->moves = 0;
	player->pv = 3;
	player->sprite = sprite;
	return (player);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->window = NULL;
	game->maps = NULL;
	game->player = NULL;
	return (game);
}

t_map_info	*init_val(void)
{
	t_map_info	*val;

	val = malloc(sizeof(t_map_info));
	if (!val)
		return (NULL);
	val->player = FALSE;
	val->exit = FALSE;
	val->collect = 0;
	return (val);
}

char	**mapcpy(char **map, int height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * height);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (new_map);
}
