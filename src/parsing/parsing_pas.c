/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:47:57 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/13 18:58:13 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '/');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (FALSE);
}

int	open_map(char *path)
{
	int	fd;

	if (ft_strcmp(path, "0") == 0)
		return (0);
	if (is_ber_file(path))
		error("Invalid file extension", NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("open map", NULL);
	return (fd);
}
