/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:47:03 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/30 16:22:46 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
# define GAME_STRUCTS_H

# include "so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_sprite
{
	mlx_image_t	*sprite;
	int			id;
}	t_sprite;

typedef struct s_map_info
{
	t_bool	has_player;
	t_bool	has_exit;
	int		collectibles;
	int		enemys;
}	t_map_info;

typedef struct s_window
{
	mlx_t	*mlx_instance;
	int		width;
	int		height;
	char	*title;
}	t_window;

typedef struct s_tile_flags
{
	t_bool	w;
	t_bool	e;
	t_bool	n;
	t_bool	s;
}	t_tile_flags;

typedef struct s_sprite_map
{
	t_sprite	*sprite;
	t_sprite	*sprite_e;
	t_sprite	*sprite_ew;
	t_sprite	*sprite_w;
	t_sprite	*sprite_n;
	t_sprite	*sprite_ns;
	t_sprite	*sprite_nw;
	t_sprite	*sprite_ne;
	t_sprite	*sprite_s;
	t_sprite	*sprite_sw;
	t_sprite	*sprite_se;
}	t_sprite_map;

typedef struct s_map
{
	char			**map_data;
	int				width;
	int				height;
	t_sprite_map	*sprite_void;
	t_sprite		*sprite_wall;
	t_sprite		*sprite_exit;
	t_sprite		*sprite_collect;
	t_sprite		*sprite_wotre;
	t_sprite		*sprite_ui;
	t_sprite		*sprite_enemy;
	t_map_info		*info;
}	t_map;

typedef struct	s_coord {
	uint32_t x;
	uint32_t y;
	uint32_t width;
	uint32_t height;
}				t_coord;
typedef struct	s_data_sprite {
	mlx_texture_t *texture_png;
	mlx_image_t* img;
	uint32_t sprite_width;
	uint32_t sprite_height;
	uint32_t sheet_width;
	uint32_t sheet_height;
	u_int8_t nb_instances;
	t_coord coord;
	char main_cara;
	char animate;
	int stats;
}				t_data_sprite;

typedef struct	s_tab_sprite {
	int nb_sprite;
	int x_main;
	int y_main;
	//t_data_map *data_map;
	t_data_sprite **tab_sprite;
}				t_tab_sprite;

typedef struct s_player
{
	t_point		*position;
	int			move_count;
	int			health_points;
	t_sprite	*sprite;
}	t_player;

typedef struct s_enemy
{
	int			nb;
	t_point		*position;
	int			move_count;
	int			health_points;
	t_sprite	*sprite;
}	t_enemy;

typedef struct s_flag
{
	t_bool		bnse;
	t_bool		r;
	t_bool		d;
	int			count;
	int			ndmap;
}	t_flag;

typedef struct s_data_map
{
	int			fps;
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_list_int	*sprites_id;
	//t_bool		game_satu;
	t_enemy		**enemy;
	mlx_image_t	*sprite_move;
	mlx_image_t	*sprite_pv;
}	t_data_map;

typedef struct s_game
{
	t_data_map	**game;
	int			i_game;
	t_flag		*flag;
	char		**paths;
	t_window	*window;
	t_bool		game_satu;
}	t_game;

#endif
