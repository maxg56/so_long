/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:36:24 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 10:51:31 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static int	open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (fd);
}

static t_bool	check_map_len(char *path, t_map *map, char *maps)
{
	char	*line;
	int		fd_map;

	fd_map = open_map(path);
	line = get_next_line(fd_map);
	map->height++;
	while (line)
	{
		if (map->width == 0)
			map->width = ft_strlen(line);
		else if (map->width != (int)ft_strlen(line))
			return (FALSE);
		maps = ft_strjoin(maps, line);
		map->height++;
		free(line);
		line = get_next_line(fd_map);
	}
	free(line);
	close(fd_map);
	return (TRUE);
}

t_bool	parse_input(int ac, char **av, t_game *game)
{
	char		*path;
	char		*maps;

	ft_printf("1");
	maps = ft_strdup("");
	if (ac == 1)
		path ="maps/p1.bar";
	else
		path = av[1];
	check_map_len(path, game->maps, maps);
	ft_printf("2");
	ft_printf("%s\n", maps);
	game->maps->map = (const char **)ft_split(maps, '\n');
	ft_printf("%d\n", game->maps->height);
	if (check_map_vide(game))
		return (FALSE);
	return (TRUE);
}
