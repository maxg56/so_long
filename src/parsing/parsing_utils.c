/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:47:57 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 22:49:49 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	is_ber_file(const char *argv)
{
	char	*extension;

	extension = ft_strrchr(argv, '/');
	if (extension == NULL)
		extension = (char *)argv;
	extension = ft_strrchr(extension, '.');
	if (extension && ft_strcmp(extension, ".ber") == 0)
		return (TRUE);
	return (FALSE);
}


int	open_map(char *path)
{
	int	fd;

	if (ft_strcmp(path, "0") == 0)
		return (0);
	if (!is_ber_file(path))
		return (exit_error("Invalid file extension"), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (exit_error("open map"), -1);
	return (fd);
}

char	**mapcpy(char **map, int height)
{
	char	**new_map;
	int		i;

	new_map = ft_arnalloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			return (NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
