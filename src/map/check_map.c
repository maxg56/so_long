/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:11:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 14:00:38 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_map_borders(t_game *game)
{
	int		y;

	y = 0;
	
	while (game->map->map_data[0][y] != '\0')
	{
		if (game->map->map_data[0][y] != WAll)
			return (FALSE);
		if (game->map->map_data[game->map->height - 1][y] != WAll)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

static t_bool	check_map_cell(t_game *game, int x, int y)
{
	if (game->map->map_data[x][y] == PLAYER && !game->map->info->has_player)
	{
		game->map->info->has_player = TRUE;
		game->player->position->x = x;
		game->player->position->y = y;
		return (TRUE);
	}
	else if (game->map->map_data[x][y] == EXIT)
	{
		if (!game->map->info->has_exit)
			game->map->info->has_exit = TRUE;
		return (TRUE);
	}
	else if (game->map->map_data[x][y] == COLLECT)
		return (game->map->info->collectibles++, TRUE);
	else if (game->map->map_data[x][y] == WAll || game->map->map_data[x][y] == VOID)
		return (TRUE);
	return (FALSE);
}

static t_bool	validate_map_structure(t_game *game)
{
	int		x;
	int		y;

	if (!check_map_borders(game))
		return (FALSE);
	x = 1;
	while (x < game->map->height )
	{
		y = 0;
		if (game->map->map_data[x][0] != WAll ||
			game->map->map_data[x][game->map->width - 1] != WAll)
			return (FALSE);
		while (y < game->map->width)
		{
			if (!check_map_cell(game, x, y))
				return (FALSE);
			y++;
		}
		x++;
	}
	if (!game->map->info->has_player ||
		!game->map->info->has_exit ||
		game->map->info->collectibles < 1)
		return (FALSE);
	return (TRUE);
}

static void	flood_fill(t_game *game, int x, int y, char **map)
{
	int	i;
	const int direction_offsets[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
	};

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
	i = 0;
	while ( i < 4)
	{
		flood_fill(game, x + direction_offsets[i][0], 
				y + direction_offsets[i][1], map);
		i++;
	}
}

void	check_path(t_game *game)
{
	char **map;
	int  collexct;

	if (validate_map_structure(game) == FALSE)
		error("[1]Invalid map (impossible to complete)", game);
	map = mapcpy(game->map->map_data, game->map->height);
	if (!map)
		error("Malloc failed 444", game);
	collexct = game->map->info->collectibles;
	free(game->map->info);
	game->map->info = init_map_info();
	flood_fill(game, game->player->position->x, game->player->position->y, map);
	if (game->map->info->has_exit != TRUE || game->map->info->collectibles != collexct)
	{
		free_tab(map);
		error("[2]Invalid map (impossible to complete)", game);
	}
	free_tab(map);
}
