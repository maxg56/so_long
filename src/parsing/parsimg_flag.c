/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsimg_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:20:16 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 14:48:27 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_flag(t_flag *flag, t_bool r, t_bool d)
{
	if (r)
	{
		flag->r = r;
		flag->count++;
	}
	if (d)
		flag->d = d;
}

static void	get_falg( int argc, char **argv, t_init_game *game)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-r") == 0)
			set_flag(game->flag, TRUE, FALSE);
		if (ft_strcmp(argv[i], "-d") == 0)
			set_flag(game->flag, FALSE, TRUE);
		if (ft_strcmp(argv[i], "-rg") == 0 || ft_strcmp(argv[i], "-gr") == 0)
			set_flag(game->flag, TRUE, TRUE);
	}
	game->flag->ndmap = argc - game->flag->count;
}

void	parse_flag(int argc, char **argv, t_init_game *game)
{
	int	i;

	i = 0;
	get_falg(argc, argv, game);
	if (game->flag->ndmap < 1)
		exit_error("Invalid number of maps");
	game->game = ft_arnalloc(sizeof(t_game *) * game->flag->ndmap);
	game->paths = ft_arnalloc(sizeof(char *) * (game->flag->ndmap + 1));
	while (i < game->flag->ndmap)
		game->game[i++] = init_game();
	if (argc != 2 && game->flag->r == FALSE)
		exit_error("Invalid number of arguments");
	i = 0;
	if (game->flag->d)
	{
		game->paths[i] = ft_strdup("maps/p1.ber");
		i++;
	}
	while (i < game->flag->ndmap)
	{
		game->paths[i] = ft_strdup(argv[i + game->flag->count]);
		if (!game->paths[i++])
			exit_error("Failed to allocate memory for path");
	}
	game->paths[i] = NULL;
}
