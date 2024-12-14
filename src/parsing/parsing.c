/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:36:24 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 03:51:09 by mgendrot         ###   ########.fr       */
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
	char	*new_maps;
	int		fd_map;
	size_t	line_len;

	fd_map = open_map(path);
	line = get_next_line(fd_map);
	if (!line)
		return (free(maps), NULL);
	while (line)
	{
		line_len = get_line_length(line);
		if (map->width == 0)
			map->width = line_len;
		else if (map->width != (int)line_len)
			return (free(line), free(maps), close(fd_map), NULL);
		new_maps = ft_strjoin(maps, line);
		if (!new_maps)
			return (free(line), free(maps), close(fd_map), NULL);
		(free(maps), free(line));
		maps = new_maps;
		line = get_next_line(fd_map);
		map->height++;
	}
	return (close(fd_map), maps);
}

t_bool	open_and_check_map(t_game *game, char *path)
{
	char	*maps;

	maps = ft_strdup("");
	if (!maps)
		return (error("Malloc failed\n map error", game), FALSE);
	maps = check_map_len(path, game->map, maps);
	if (!maps)
		return (error("map error", game), FALSE);
	game->map->map_data = ft_split(maps, '\n');
	free(maps);
	if (!game->map->map_data)
		return (error("[2]map error", game), FALSE);
	printf("map %c\n", game->map->map_data[0][0]);
	return (check_path(game));
}
