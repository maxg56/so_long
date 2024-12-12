/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:11:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 08:30:31 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_map_borders(t_game *game)
{
	int		y;

	y = 0;
	while (game->maps->map[0][y] != '\0')
	{
		if (game->maps->map[0][y] != MUR)
			return (FALSE);
		if (game->maps->map[game->maps->height - 1][y] != MUR)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

static t_bool	check_map_cell(t_game *game, int x, int y)
{
	if (game->maps->map[x][y] == PLAYER && !game->maps->info->player)
	{
		game->maps->info->player = TRUE;
		game->player->point->x = x;
		game->player->point->y = y;
		return (TRUE);
	}
	else if (game->maps->map[x][y] == EXIT && !game->maps->info->exit)
	{
		if (!game->maps->info->exit)
			game->maps->info->exit = TRUE;
		return (TRUE);
	}
	else if (game->maps->map[x][y] == COLLECT)
		return (game->maps->info->collect++, TRUE);
	else if (game->maps->map[x][y] == MUR || game->maps->map[x][y] == VIDE)
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
	while (x < game->maps->height - 1)
	{
		y = 0;
		if (game->maps->map[x][0] != MUR ||
			game->maps->map[x][game->maps->width - 1] != MUR)
			return (FALSE);
		while (y < game->maps->width)
		{
			if (!check_map_cell(game, x, y))
				return (FALSE);
			y++;
		}
		x++;
	}
	if (!game->maps->info->player ||
		!game->maps->info->exit ||
		game->maps->info->collect < 1)
		return (FALSE);
	return (TRUE);
}

static void	flood_fill(t_game *game, int x, int y, char **map)
{
	int	i;

	if (y < 0 || y >= game->maps->height || x < 0 || x >= game->maps->width)
		return ;
	if (map[y][x] == MUR || map[y][x] == '2')
		return ;
	if (map[y][x] == COLLECT)
		game->maps->info->collect++;
	if (map[y][x] == EXIT)
		game->maps->info->exit = TRUE;
	if (map[y][x] == PLAYER)
		game->maps->info->player = TRUE;
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

	if (validate_map_structure(game) == FALSE)
		error("Invalid map (impossible to complete)", game);
	map = mapcpy(game->maps->map, game->maps->height);
	if (!map)
		error("Malloc failed 444", game);
	free(game->maps->info);
	game->maps->info = init_val();
	flood_fill(game, game->player->point->x, game->player->point->y, map);
	if (game->maps->info->exit != TRUE)
	{
		free_tab(map);
		error("Invalid map (impossible to complete)", game);
	}
	free_tab(map);
}
