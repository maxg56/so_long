/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsimg_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:20:16 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/14 03:53:41 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_flag(t_flag *flag, t_bool r, t_bool g)
{
	if (r)
	{
		flag->r = r;
		flag->count++;
	}
	if (g)
		flag->g = g;
}

void	get_falg( int argc, char **argv, t_init_game *game)
{
	int		i;
	t_bool	flag;

	flag = FALSE;
	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-r") == 0)
			set_flag(game->flag, TRUE, FALSE);
		if (ft_strcmp(argv[i], "-g") == 0)
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
		exit_error("Invalid number of maps", game);
	game->game = malloc(sizeof(t_game *) * game->flag->ndmap);
	game->paths = malloc(sizeof(char *) * (game->flag->ndmap + 1));
	while (i < game->flag->ndmap)
		game->game[i++] = init_game();
	if (argc != 2 && game->flag->r == FALSE)
		exit_error("Invalid number of arguments", game);
	i = 0;
	if (game->flag->g)
	{
		game->paths[i] = ft_strdup("maps/p1.ber");
		i++;
	}
	while (i < game->flag->ndmap)
	{
		game->paths[i] = ft_strdup(argv[i + game->flag->count]);
		if (!game->paths[i++])
            exit_error("Failed to allocate memory for path", game);
	}
	game->paths[i] = NULL;
}
