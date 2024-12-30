/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:30 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/30 16:24:10 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>

# include "list_int.h"
# include "game_structs.h"

# define TILE_SIZE 64

# define Z_BACKGROUND 0
# define Z_DEFAULT 1
# define Z_DEFAULT_PLAYER 5
# define Z_DEFAULT_UI 10
# define Z_DEFAULT_ENEMY 5

# define PATH_SPRITE_PLAYER "assets/player.png"
# define PATH_SPRITE_WALL "assets/wall.png"
# define PATH_SPRITE_EXIT "assets/exit.png"
# define PATH_SPRITE_COLLECT "assets/collect.png"
# define PATH_SPRITE_VOID "assets/empty/empty.png"
# define PATH_SPRITE_VOID_E "assets/empty/empty_E.png"

# define PATH_SPRITE_VOID_EW "assets/empty/empty_EW.png"
# define PATH_SPRITE_VOID_W "assets/empty/empty_W.png"
# define PATH_SPRITE_VOID_N "assets/empty/empty_N.png"
# define PATH_SPRITE_VOID_NS "assets/empty/empty_NS.png"
# define PATH_SPRITE_VOID_NW "assets/empty/empty_NW.png"
# define PATH_SPRITE_VOID_NE "assets/empty/empty_NE.png"
# define PATH_SPRITE_VOID_S "assets/empty/empty_S.png"
# define PATH_SPRITE_VOID_SW "assets/empty/empty_SW.png"
# define PATH_SPRITE_VOID_SE "assets/empty/empty_SE.png"
# define PATH_SPRITE_UI "assets/ui.png"
# define PATH_SPRITE_WOTRE "assets/4.png"

typedef enum e_ement
{
	WAll = '1',
	EXIT = 'E',
	COLLECT = 'C',
	VOID = '0',
	PLAYER = 'P',
}	t_ement;

// set

void			set_move(t_data_map *game );
void			set_pv(t_data_map *game);
void			set_blak(t_data_map *game);
void			set_tile(t_data_map *game, t_sprite *sprite, t_point *point, \
char *path);
void			set_tlse_z(t_data_map *game, t_sprite *sprite, t_point *point, \
char *path);
void			set_player(t_data_map *game);
void			set_map(t_data_map *game);
void			lood_game(t_game *ig);
t_bool			open_and_check_map(t_data_map *game, char *path);
//init

t_sprite		*init_sprite(void);
t_point			*init_point(void);
t_window		*init_window(char *title, int width, int height);
t_map			*init_map(void);
t_player		*init_player(int x, int y);
t_data_map			*init_game(void);
t_map_info		*init_map_info(void);
t_flag			*init_flag(void);
t_game		*init_init_game(void);
t_sprite_map	*init_sprite_map(void);

//parse

void			parse_flag(int argc, char **argv, t_game *game);
t_bool			open_and_check_map(t_data_map *game, char *path);
t_bool			parse_input(int ac, char **av, t_data_map *game);
t_bool			check_path(t_data_map *game);

// utils

mlx_image_t		*load_sprite_image(char *path, mlx_t *mlx);
int				open_map(char *path);
char			**mapcpy(char **map, int height);

void			set_instance_coordinates(mlx_image_t *sprite, int t, \
t_point *point, int z);
void			move_player(t_data_map *game, int x, int y);

//error

void			set_player_coordinates(t_data_map *game );
void			closed_game(t_game	*g);
void			exit_error(char *message);
void			exit_game( void *param);

// uload

void			unload_add(t_data_map *game);
void			choose_tile_sprite(t_data_map *game, t_point *point);
#endif