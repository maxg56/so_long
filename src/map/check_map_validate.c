/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:59:56 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 06:36:09 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_stack(t_stack *stack);

static t_bool is_valid_move(int nx, int ny, int height, int width, char **map)
{
	if (nx < 0 || nx >= height || ny < 0 || ny >= width || !map[nx])
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
		printf("point: (%d, %d) %c\n", point->x, point->y , map[point->x][point->y]);
		nx = point->x + direction_offsets[i][0];
		ny = point->y + direction_offsets[i][1];
		printf("1\n");
		if (is_valid_move(nx, ny, game->maps->height, game->maps->width, map))
		{
			ft_stackadd(stack, ft_stacknew(nx, ny));
			map[nx][ny] = MUR;
			//print_stack(*stack);
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

t_bool	dfs(t_game *game)
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
	for (int i = 0; game->maps->map[i]; i++)
		printf("map: %s\n", game->maps->map[i]);	
	while (stack)
	{
		vex = stack->vex;
		stack = stack->next;
		if (!vex)
		{
			printf("vex is null\n");
			break ;
		}
		if (map[vex->x][vex->y] == EXIT)
			return (free_tab(map), free_stack(stack), TRUE);
		check_possible_moves(game, map, vex, &stack);
		map[vex->x][vex->y] = MUR;
		free(vex);
		print_stack(stack);
	}
	print_stack(stack);
	printf("stack is empty\n");
	free_tab(map);
	free_stack(stack);
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:36:24 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 06:33:41 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



static size_t	get_line_length(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len);
}

static char	*check_map_len(
	char *path,
	t_map *map,
	char *maps
)
{
	char	*line;
	char	*tmp;
	int		fd_map;
	size_t	line_len;

	fd_map = open_map(path);
	line = get_next_line(fd_map);
	if (!line)
		return (FALSE);
	map->height = 0;
	tmp = maps;
	while (line)
	{
		line_len = get_line_length(line);
		if (map->width == 0)
			map->width = get_line_length(line);
		else if (map->width != (int)line_len)
			return (free(line), free(maps), free(tmp), close(fd_map), NULL);
		maps = ft_strjoin(maps, line);
		(free(line), free(tmp));
		line = get_next_line(fd_map);
		map->height++;
		tmp = maps;
	}
	(free(line), close(fd_map));
	return (maps);
}

t_bool	parse_input(int ac, char **av, t_game *game)
{
	char		*path;
	char		*maps;

	if (ac != 2)
		return (error("Invalid number of arguments", game), FALSE);
	maps = ft_strdup("");
	if (!maps)
		return (error("Malloc failed\n map error", game), FALSE);
	if (ft_strcmp(av[1], "-g") == 0)
		path = "maps/p1.bar";
	else
		path = av[1];
	maps = check_map_len(path, game->maps, maps);
	if (!maps)
		return (free(maps), error(" map error", game), FALSE);
	game->maps->map = (const char **)ft_split(maps, '\n');
	free(maps);
	if (!game->maps->map)
		return (error(" map error", game), FALSE);
	for (int i = 0; game->maps->map[i]; i++)
		printf("map: %s\n", game->maps->map[i]);	
	if (validate_map_structure(game) == FALSE)
		return (error(" map error", game), FALSE);
	if (dfs(game) == FALSE)
		return (error(" map error", game), FALSE);
	return (TRUE);
}

t_stack	*ft_stacknew(int x, int y)
{
	t_stack	*stak;

	stak = malloc(sizeof(t_stack));
	if (!stak)
		return (NULL);
	stak->next = NULL;
	stak->vex = malloc(sizeof(t_point));
	if (!stak->vex)
		return (free(stak), NULL);
	stak->vex->x = x;
	stak->vex->y = y;
	return (stak);
}

void	ft_stackadd(t_stack **stak, t_stack *new)
{
	if (!stak || !new)
		return ;
	new->next = *stak;
	*stak = new;
}

t_point *ft_stackpop(t_stack *stack)
{
	t_stack	*top;
	t_point	*vex;

	if (!stack)
		return (NULL);

	top = stack;
	vex = top->vex;
	stack = top->next;
	free(top);
	return (vex);
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