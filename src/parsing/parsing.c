/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:36:24 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 16:07:25 by mgendrot         ###   ########.fr       */
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

static t_bool	check_map_len(t_map *map, char *line)
{
	size_t	line_len;

	if (!map || !line)
		return (FALSE);
	line_len = get_line_length(line);
	if (line_len == 0)
		return (FALSE);
	if (map->width == 0)
		map->width = line_len;
	else if (map->width != (int)line_len)
		return (FALSE);
	return (TRUE);
}

static char	*check_len_and_open(
	char *path,
	t_map *map,
	char *maps
)
{
	char	*line;
	char	*new_maps;
	int		fd_map;

	fd_map = open_map(path);
	line = get_next_line(fd_map);
	if (!line)
		return (NULL);
	while (line)
	{
		if (!check_map_len(map, line))
			return (close(fd_map), NULL);
		new_maps = ft_strjoin(maps, line);
		if (!new_maps)
			return (close(fd_map), NULL);
		maps = new_maps;
		line = get_next_line(fd_map);
		map->height++;
	}
	return (close(fd_map), maps);
}

t_bool	open_and_check_map(t_data_map *game, char *path)
{
	char	*maps;

	maps = ft_strdup("");
	if (!maps)
		return (exit_error("Malloc failed\n map error"), FALSE);
	maps = check_len_and_open(path, game->map, maps);
	if (!maps)
		return (exit_error("map error"), FALSE);
	game->map->map_data = ft_split(maps, '\n');
	if (!game->map->map_data)
		return (exit_error("[2]map error"), FALSE);
	return (check_path(game));
}
