/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:36:24 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 11:00:20 by mgendrot         ###   ########.fr       */
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

static size_t	get_line_length(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len);
}

static t_bool	check_map_len(char *path, t_map *map, char *maps)
{
	char	*line;
	char	*temp;
	int		fd_map;
	size_t	line_len;

	fd_map = open_map(path);
	line = get_next_line(fd_map);
	if (!line)
		return (FALSE);
	map->height = 0;
	while (line)
	{
		line_len = get_line_length(line);
		if (map->width == 0)
			map->width = get_line_length(line);
		else if (map->width != (int)line_len)
			return (free(line), free(maps), close(fd_map), FALSE);
		temp = maps;
		maps = ft_strjoin(maps, line);
		(free(temp), free(line));
		line = get_next_line(fd_map);
		map->height++;
	}
	close(fd_map);
	return (TRUE);
}

t_bool	parse_input(int ac, char **av, t_game *game)
{
	char		*path;
	char		*maps;

	maps = ft_strdup("");
	if (!maps)
		return (FALSE);
	if (ac == 1)
		path = "maps/p1.bar";
	else
		path = av[1];
	if (!check_map_len(path, game->maps, maps))
	{
		free(maps);
		return (FALSE);
	}
	game->maps->map = (const char **)ft_split(maps, '\n');
	free(maps);
	if (!game->maps->map)
		return (FALSE);
	if (check_map_vide(game))
		return (FALSE);
	return (TRUE);
}
