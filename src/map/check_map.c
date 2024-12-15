/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:11:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 21:10:47 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_map_borders(t_game *game)
{
	int		x;

	x = 0;
	while (x < game->map->width)
	{
		if (game->map->map_data[0][x] != WAll)
			return (FALSE);
		if (game->map->map_data[game->map->height - 1][x] != WAll)
			return (FALSE);
		x++;
	}
	return (TRUE);
}

static t_bool	check_map_cell(t_game *game, int x, int y)
{
	if (game->map->map_data[y][x] == PLAYER)
	{
		game->map->info->has_player = TRUE;
		game->player->position->x = x;
		game->player->position->y = y;
		return (TRUE);
	}
	else if (game->map->map_data[y][x] == EXIT)
	{
		if (!game->map->info->has_exit)
			game->map->info->has_exit = TRUE;
		return (TRUE);
	}
	else if (game->map->map_data[y][x] == COLLECT)
		return (game->map->info->collectibles++, TRUE);
	else if (game->map->map_data[y][x] == WAll ||
			game->map->map_data[y][x] == VOID)
		return (TRUE);
	return (FALSE);
}

static t_bool	validate_map_structure(t_game *game)
{
	int		x;
	int		y;

	if (!check_map_borders(game))
		return (FALSE);
	y = 1;
	while (y < game->map->height -1)
	{
		x = 0;
		if (game->map->map_data[y][0] != WAll ||
			game->map->map_data[y][game->map->width - 1] != WAll)
			return (FALSE);
		while (x < game->map->width)
		{
			if (!check_map_cell(game, x, y))
				return (FALSE);
			x++;
		}
		y++;
	}
	if (!game->map->info->has_player || \
		!game->map->info->has_exit || \
		game->map->info->collectibles < 1)
		return (FALSE);
	return (TRUE);
}

static void	flood_fill(t_game *game, int x, int y, char **map)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width)
		return ;
	if (map[y][x] == WAll || map[y][x] == '2')
		return ;
	if (map[y][x] == COLLECT)
		game->map->info->collectibles++;
	if (map[y][x] == EXIT)
		game->map->info->has_exit = TRUE;
	if (map[y][x] == PLAYER)
		game->map->info->has_player = TRUE;
	map[y][x] = '2';
	flood_fill(game, x + 1, y, map);
	flood_fill(game, x - 1, y, map);
	flood_fill(game, x, y - 1, map);
	flood_fill(game, x, y + 1, map);
}

t_bool	check_path(t_game *game)
{
	char	**map;
	int		collexct;

	if (validate_map_structure(game) == FALSE)
		return (exit_error("[1] Invalid map (impossible to complete)"), FALSE);
	map = mapcpy(game->map->map_data, game->map->height);
	if (!map)
		exit_error("Malloc failed");
	collexct = game->map->info->collectibles;
	game->map->info = init_map_info();
	flood_fill(game, game->player->position->x, game->player->position->y, map);
	if (game->map->info->has_exit != TRUE || \
		game->map->info->collectibles != collexct)
		exit_error("[2]Invalid map (impossible to complete)");
	return (TRUE);
}
