/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:11:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 02:23:25 by mgendrot         ###   ########.fr       */
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
	else if (game->maps->map[x][y] == EXIT)
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



t_bool	validate_map_structure(t_game *game)
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
