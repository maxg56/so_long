/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:47:03 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/14 05:11:10 by mgendrot         ###   ########.fr       */
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
}	t_map_info;

typedef struct s_window
{
	mlx_t	*mlx_instance;
	int		width;
	int		height;
	char	*title;
}	t_window;

typedef struct s_t
{
	t_bool	w;
	t_bool	e;
	t_bool	n;
	t_bool	s;
}	t_t;

typedef struct s_sprite_map
{
	t_sprite	*sprite;
	t_sprite	*sprite_e;
	t_sprite	*sprite_ens;
	t_sprite	*sprite_ews;
	t_sprite	*sprite_w;
	t_sprite	*sprite_wns;
	t_sprite	*sprite_n;
	t_sprite	*sprite_ns;
	t_sprite	*sprite_nw;
	t_sprite	*sprite_ne;
	t_sprite	*sprite_new;
	t_sprite	*sprite_news;
	t_sprite	*sprite_s;
	t_sprite	*sprite_sw;
	t_sprite	*sprite_se;
	t_sprite	*sprite_sew;
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
	t_map_info		*info;
}	t_map;

typedef struct s_player
{
	t_point		*position;
	int			move_count;
	int			health_points;
	t_sprite	*sprite;
}	t_player;

typedef struct s_flag
{
	t_bool		bnse;
	t_bool		r;
	t_bool		g;
	int			count;
	int			ndmap;
}	t_flag;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_list_int	*sprites_id;
	t_bool		game_satu;
}	t_game;

typedef struct s_init_game
{
	t_game		**game;
	int			i_game;
	t_flag		*flag;
	char		**paths;
	t_window	*window;
}	t_init_game;

#endif
