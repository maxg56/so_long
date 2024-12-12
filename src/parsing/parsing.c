/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:36:24 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 20:21:30 by mgendrot         ###   ########.fr       */
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
	check_path(game);
	return (TRUE);
}

