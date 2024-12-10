/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:11:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 09:53:47 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_lime_map(t_game *game)
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

static t_bool	check_car_map(t_game *game, int x, int y)
{
	if (game->maps->map[x][y] == PLAYER && !game->maps->info->player)
	{
		game->maps->info->player = TRUE;
		game->player->pos->x = x;
		game->player->pos->y = y;
		return (TRUE);
	}
	else if (game->maps->map[x][y] == EXIT || !game->maps->info->exit)
		return (game->maps->info->exit = TRUE, TRUE);
	else if (game->maps->map[x][y] == COLLECT)
		return (game->maps->info->collect++, TRUE);
	else if (game->maps->map[x][y] == MUR && game->maps->map[x][y] == VIDE)
		return (TRUE);
	return (FALSE);
}

t_bool	check_map_vide(t_game *game)
{
	int		x;
	int		y;

	if (!check_lime_map(game))
		return (FALSE);
	x = 0;
	while (x++ < game->maps->height - 2)
	{
		y = -1;
		if (game->maps->map[x][0] != MUR ||
			game->maps->map[x][game->maps->width - 1] != MUR)
			return (FALSE);
		while (y++ < game->maps->width)
		{
			if (!check_car_map(game, x, y))
				return (FALSE);
		}
	}
	if (!game->maps->info->player || !game->maps->info->exit ||
		game->maps->info->collect < 1)
		return (FALSE);
	return (TRUE);
}



t_bool	check_map_valid(t_game *game)
{
	char	**map;
	t_stack	*stack;
	t_vex	*vex;

	stack = ft_stacknew(game->player->pos->x, game->player->pos->y);
	map = mapcpy((char **)game->maps->map, game->maps->height);
	while (stack)
	{
		vex = ft_stackget_back(&stack);
		if (map[vex->x][vex->y] == EXIT)
			return (free_tab(map), free_stack(stack), TRUE);
		else if (vex->x > 0 && map[vex->x- 1][vex->y] == VIDE)
			ft_stackadd(&stack, ft_stacknew(vex->x - 1, vex->y));
		if (vex->y > 0 && map[vex->x][vex->y - 1] == VIDE)
			ft_stackadd(&stack, ft_stacknew(vex->x, vex->y - 1));
		if (vex->x < game->maps->height && map[vex->x + 1][vex->y] == VIDE)
			ft_stackadd(&stack, ft_stacknew(vex->x + 1, vex->y));
		if (vex->y < game->maps->width && map[vex->x][vex->y + 1] == VIDE)
			ft_stackadd(&stack, ft_stacknew(vex->x, vex->y + 1));
		map[vex->x][vex->y] = MUR;
		free(vex);
	}
	free_tab(map);
	free_stack(stack);
	return (FALSE);
}
