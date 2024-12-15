/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:30 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 07:06:05 by mgendrot         ###   ########.fr       */
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
# define PATH_SPRITE_VOID_ENS "assets/empty/empty_ENS.png"
# define PATH_SPRITE_VOID_EWS "assets/empty/empty_EWS.png"
# define PATH_SPRITE_VOID_EW "assets/empty/empty_EW.png"
# define PATH_SPRITE_VOID_W "assets/empty/empty_W.png"
# define PATH_SPRITE_VOID_WNS "assets/empty/empty_WNS.png"
# define PATH_SPRITE_VOID_N "assets/empty/empty_N.png"
# define PATH_SPRITE_VOID_NS "assets/empty/empty_NS.png"
# define PATH_SPRITE_VOID_NW "assets/empty/empty_NW.png"
# define PATH_SPRITE_VOID_NE "assets/empty/empty_NE.png"
# define PATH_SPRITE_VOID_NEW "assets/empty/empty_NEW.png"
# define PATH_SPRITE_VOID_NEWS "assets/empty/empty_NEWS.png"
# define PATH_SPRITE_VOID_S "assets/empty/empty_S.png"
# define PATH_SPRITE_VOID_SW "assets/empty/empty_SW.png"
# define PATH_SPRITE_VOID_SE "assets/empty/empty_SE.png"
# define PATH_SPRITE_VOID_SEW "assets/empty/empty_SEW.png"
# define PATH_SPRITE_UI "assets/ui.png"
# define PATH_SPRITE_ENEMY "assets/enemy.png"

# define PATH_SPRITE_WOTRE "assets/4.png"
typedef enum e_ement
{
	WAll = '1',
	EXIT = 'E',
	COLLECT = 'C',
	VOID = '0',
	PLAYER = 'P',
	ENEMY = 'N',
}	t_ement;


// set
void			set_blak(t_game *game);
void			set_tlse(t_game *game, t_sprite *sprite, t_point *point, \
char *path);
void			set_tlse_z(t_game *game, t_sprite *sprite, t_point *point, \
char *path);
void			set_player(t_game *game);
void			set_map(t_game *game);
void			lood_game(t_init_game *ig);
t_bool			open_and_check_map(t_game *game, char *path);
//init

t_sprite		*init_sprite(void);
t_point			*init_point(void);
t_window		*init_window(char *title, int width, int height);
t_map			*init_map(void);
t_player		*init_player(int x, int y);
t_game			*init_game(void);
t_map_info		*init_map_info(void);
t_flag			*init_flag(void);
t_init_game		*init_init_game(void);
t_sprite_map	*init_sprite_map(void);

//enemy
int				cote_enemy(t_game *game);
t_enemy			*init_enemy(int x, int y);
void			move_enemy(t_game *game, t_enemy *enemy);
void			set_enemy(t_game *game, t_enemy *enemy, int nb);
void			enemys_move(t_game *game);


//parse

void			parse_flag(int argc, char **argv, t_init_game *game);
t_bool			open_and_check_map(t_game *game, char *path);
t_bool			parse_input(int ac, char **av, t_game *game);
t_bool			check_path(t_game *game);

// utils

mlx_image_t		*open_image(char *path, mlx_t *mlx);
int				open_map(char *path);
char			**mapcpy(char **map, int height);

void			set_instance_coordinates(mlx_image_t *sprite, int t, \
t_point *point, int z);
void			set_instance_z(mlx_image_t *sprite, int t, int z);
void			move_player(t_game *game, int x, int y);

//error

void			set_coordinates(t_game *game );
void			closed_game(t_init_game	*g);
void			exit_error(char *message);
void			exit_game( void *param);

// uload

void			uload_sprite(t_game *game, t_sprite *s);
void			uload_sprite_map(t_game *game, t_sprite_map *sm);
void			uload_map(t_game *game);
void			uload_player(t_game *game);
void			unload_add(t_game *game);
void			choose_tatse(t_game *game, t_point *point);
#endif