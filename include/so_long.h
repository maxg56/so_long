/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:30 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 08:29:35 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



static mlx_image_t* image;
static mlx_key_data_t keydata;

# define w 6464

# define PATH_SPRITE_PLAYER "assets/player.xpm"
# define PATH_SPRITE_MUR "assets/mur.xpm"
# define PATH_SPRITE_EXIT "assets/exit.xpm"
# define PATH_SPRITE_COLLECT "assets/collect.xpm"

# define PLAYER 'P'
# define MUR '1'
# define EXIT 'E'
# define COLLECT 'C'
# define VIDE '0'

// so_long.h
extern const int direction_offsets[4][2];

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;



typedef struct s_map_info
{
	t_bool	player;
	t_bool	exit;
	int		collect;
}	t_map_info;

typedef struct s_window
{
	mlx_t  *mlx;
	int		width;
	int		height;
	char	*title;
}	t_window;

typedef struct s_map
{
	const int	direction_offsets;
 	char		**map;
	int			width;
	int			height;
	mlx_image_t *sprat_void;
	mlx_image_t	*sprat_mur;
	mlx_image_t	*sprat_exit;
	t_map_info	*info;
}	t_map;

typedef struct s_player
{
	t_point	*point;
	int			moves;
	int			pv;
	mlx_image_t	*sprite;
}	t_player;

typedef struct s_game
{
	t_window	*window;
	t_map		*maps;
	t_player	*player;
	const int	direction_offsets;
}	t_game;

t_window	*init_window(char *title, int width, int height);
t_map		*init_map(void);
t_player	*init_player(int x, int y, void *sprite);
t_game		*init_game(void);
t_map_info	*init_val(void);

t_bool		parse_input(int ac, char **av, t_game *game);
void		check_path(t_game *game);


mlx_image_t *open_image(char *path, mlx_t *mlx);

char		**mapcpy(char **map, int height);
int			open_map(char *path);

void		set_map(t_game *game);
void 		set_corde_inst(mlx_image_t *sprite, int t, t_point *point, int z);
void		set_z(mlx_image_t *sprite, int t,int z);
void		set_corde(t_game *game);
void		move_player(t_game *game, int x, int y);
//error

void		error(char *message, t_game *game);
void 		exit_game(t_game *game);

// free

void		free_map(t_map *map);
void		free_game(t_game *game);
void		free_map_info(t_map_info *val);
void		free_tab(char **tab);

#endif