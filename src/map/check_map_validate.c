/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:59:56 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 03:36:43 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_stack(t_stack *stack);

static t_bool is_valid_move(int nx, int ny, int height, int width, char **map)
{
	if (nx < 0 || nx >= height || ny < 0 || ny >= width)
		return (FALSE);
	if (map[nx][ny] == VIDE || map[nx][ny] == COLLECT || map[nx][ny] == EXIT)
		return (TRUE);
	return (FALSE);
}


static void	check_possible_moves(
	t_game *game,
	char **map,
	t_point *point,
	t_stack **stack
	)
{
	int	i;
	int	nx;
	int	ny;

	i = 0;
	while (i < 4)
	{
		nx = point->x + direction_offsets[i][0];
		ny = point->y + direction_offsets[i][1];
		if (is_valid_move(nx, ny, game->maps->height, game->maps->width, map))
		{
			ft_stackadd(stack, ft_stacknew(nx, ny));
			map[nx][ny] = MUR;
		}
		i++;
	}
}

void print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("Stack: (%d, %d) ->", tmp->vex->x, tmp->vex->y);
		tmp = tmp->next;
	}
	printf("\n");
}

t_bool	validate_map_playable(t_game *game)
{
	char		**map;
	t_stack		*stack;
	t_point		*vex;

	stack = ft_stacknew(game->player->point->x, game->player->point->y);
	if (!stack)
		return (FALSE);
	map = mapcpy((char **)game->maps->map, game->maps->height);
	if (!map)
		return (free_stack(stack), FALSE);
	while (stack)
	{
		vex = ft_stackpop(&stack);
		if (!vex)
			break ;
		if (map[vex->x][vex->y] == EXIT)
			return (free_tab(map), free_stack(stack), TRUE);
		check_possible_moves(game, map, vex, &stack);
		map[vex->x][vex->y] = MUR;
		free(vex);
	}
	free_tab(map);
	free_stack(stack);
	return (FALSE);
}
