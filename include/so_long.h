/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:30 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

# include "config.h"
# include "game_structs.h"

typedef enum e_ement
{
	WAll = '1',
	EXIT = 'E',
	COLLECT = 'C',
	VOID = '0',
	PLAYER = 'P',
}	t_ement;

// init

t_point			*init_point(void);
t_player		*init_player(int x, int y);
t_map			*init_map(void);
t_map_info		*init_map_info(void);
t_data_map		*init_data_map(void);
t_flag			*init_flag(void);
t_game			*init_game(void);

// parse

void			parse_flag(int argc, char **argv, t_game *game);
t_bool			open_and_check_map(t_data_map *game, char *path);
t_bool			check_path(t_data_map *game);
int				open_map(char *path);
char			**mapcpy(char **map, int height);

// window / assets

mlx_t			*get_mlx(void);
void			open_window(t_game *g);
void			reserve_depth(t_game *g);
void			load_assets(t_game *g);
void			free_assets(t_game *g);
mlx_image_t		*texture_scaled(mlx_texture_t *t, uint32_t k);

// iso : projection, pixels, tuiles generees

double			iso_wx(double x, double y);
double			iso_wy(double x, double y);
int				depth_of(int x, int y, int layer);
t_data_map		*cur_lvl(t_game *g);
void			tex_sample(mlx_texture_t *t, t_rect r, double *uv,
					uint8_t *out);
void			px_shade(uint8_t *c, double s);
void			px_blend(mlx_image_t *img, int x, int y, uint8_t *c);
void			img_fill(mlx_image_t *img, uint8_t *c);
void			set_rgba(uint8_t *c, uint32_t hex, uint8_t a);
t_bool			diamond_uv(int px, int py, double *uv);
mlx_image_t		*build_floor(t_game *g, double shade);
mlx_image_t		*build_wall(t_game *g, int height);
mlx_image_t		*build_exit(int frame, t_bool open);

// rendu

mlx_image_t		*track_img(t_data_map *l, mlx_image_t *img);
void			put_tile(t_game *g, mlx_image_t *img, t_point *p, int lift);
void			render_map(t_game *g);
void			camera_update(t_game *g, double dt);
void			camera_snap(t_game *g);

// animations

void			player_init_sprite(t_game *g);
void			player_anim_update(t_game *g, double dt);
void			player_place(t_game *g);
void			player_queue(t_game *g, int dx, int dy);
void			player_update(t_game *g, double dt);
void			props_init(t_game *g);
void			props_update(t_game *g, double dt);
void			prop_take(t_game *g, int x, int y);
void			exit_init(t_game *g);
void			exit_update(t_game *g, double dt);
void			exit_open(t_game *g);

// ui / ecrans

void			hud_refresh(t_game *g);
void			hud_delete(t_game *g);
void			overlay_show(t_game *g, char **lines);
void			overlay_hide(t_game *g);
void			overlay_update(t_game *g, double dt);
void			set_state(t_game *g, t_state st);

// niveaux / boucle

void			load_level(t_game *g);
void			unload_level(t_game *g);
void			reset_level_data(t_data_map *l);
void			restart_level(t_game *g);
void			next_level(t_game *g);
void			restart_all(t_game *g);
void			loop_hook(void *param);
void			key_hook(mlx_key_data_t keydata, void *param);
void			close_hook(void *param);

// erreurs / sortie

void			exit_error(char *message);
void			exit_game(t_game *g);

#endif
