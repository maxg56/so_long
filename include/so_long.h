/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:30 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/12 12:26:57 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "game_structs.h"

static mlx_image_t* image;
static mlx_key_data_t keydata;


# define TILE_SIZE 64
# define Z_DEFAULT 1
# define Z_DEFAULT_PLAYER 3

# define PATH_SPRITE_PLAYER "assets/player.png"
# define PATH_SPRITE_WALL "assets/wall.png"
# define PATH_SPRITE_EXIT "assets/exit.pug"
# define PATH_SPRITE_COLLECT "assets/collect.png"
# define PATH_SPRITE_VOID "assets/empty.png"

# define PLAYER 'P'
# define WAll '1'
# define EXIT 'E'
# define COLLECT 'C'
# define VOID '0'


void		set_void(t_game *game, int x, int y , int z);
t_window	*init_window(char *title, int width, int height);
t_map		*init_map(void);
t_player	*init_player(int x, int y, void *sprite);
t_game		*init_game(void);
t_map_info	*init_map_info(void);

t_bool		parse_input(int ac, char **av, t_game *game);
void		check_path(t_game *game);


mlx_image_t *open_image(char *path, mlx_t *mlx);

char		**mapcpy(char **map, int height);
int			open_map(char *path);

void		set_map(t_game *game);
void		set_corde(t_game *game);
void		set_instance_coordinates(mlx_image_t *sprite, int t, t_point *point, int z);
void		set_instance_z(mlx_image_t *sprite,int t, int z);
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