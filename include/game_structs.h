/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:47:03 by max_dev           #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
# define GAME_STRUCTS_H

# include "MLX42.h"
# include "libft.h"
# include "config.h"

# define MAX_LVL_IMGS 16

typedef enum e_state
{
	ST_PLAY,
	ST_PAUSE,
	ST_LEVEL_DONE,
	ST_GAME_OVER,
	ST_VICTORY,
}	t_state;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_rect;

typedef struct s_map_info
{
	t_bool	has_player;
	t_bool	has_exit;
	int		collectibles;
	int		enemys;
}	t_map_info;

typedef struct s_map
{
	char		**map_data;
	char		**map_orig;
	int			width;
	int			height;
	int			total_collect;
	t_map_info	*info;
}	t_map;

/* animation image par image d'une feuille de sprites */
typedef struct s_anim
{
	double	timer;
	int		frame;
	int		row;
	t_bool	flip;
	t_bool	dirty;
}	t_anim;

/* interpolation d'une case a l'autre */
typedef struct s_tween
{
	t_bool	active;
	double	t;
	int		dx;
	int		dy;
}	t_tween;

typedef struct s_player
{
	t_point		*position;
	t_point		spawn;
	int			move_count;
	int			health_points;
	mlx_image_t	*img;
	t_anim		anim;
	t_tween		tw;
	double		fx;
	double		fy;
	int			queued_x;
	int			queued_y;
}	t_player;

/* objet ramassable anime (flottement puis "pop") */
typedef struct s_prop
{
	int		x;
	int		y;
	int32_t	inst;
	double	phase;
	double	pop;
	t_bool	taken;
}	t_prop;

typedef struct s_exit
{
	int			x;
	int			y;
	mlx_image_t	*closed;
	mlx_image_t	*open[EXIT_FRAMES];
	double		timer;
	int			frame;
	t_bool		is_open;
}	t_exit;

typedef struct s_hud
{
	mlx_image_t	*moves;
	mlx_image_t	*items;
	mlx_image_t	*level;
}	t_hud;

typedef struct s_data_map
{
	t_map		*map;
	t_player	*player;
	t_prop		*props;
	int			nb_props;
	t_exit		exit;
	mlx_image_t	*collect_img;
	mlx_image_t	*imgs[MAX_LVL_IMGS];
	int			nb_imgs;
	t_hud		hud;
}	t_data_map;

typedef struct s_assets
{
	mlx_texture_t	*sheet;
	mlx_texture_t	*grass;
	mlx_texture_t	*stone;
	mlx_texture_t	*collect;
}	t_assets;

typedef struct s_overlay
{
	mlx_image_t	*dim;
	mlx_image_t	*panel;
	mlx_image_t	*lines[OV_LINES];
	int			nb_lines;
	double		fade;
	t_bool		visible;
}	t_overlay;

typedef struct s_cam
{
	double	x;
	double	y;
	int		ox;
	int		oy;
	t_bool	ready;
}	t_cam;

typedef struct s_flag
{
	t_bool		bnse;
	t_bool		r;
	t_bool		d;
	int			count;
	int			ndmap;
}	t_flag;

typedef struct s_game
{
	t_data_map	**game;
	int			i_game;
	t_flag		*flag;
	char		**paths;
	t_bool		game_satu;
	t_state		state;
	t_assets	assets;
	t_overlay	ov;
	t_cam		cam;
	int			win_w;
	int			win_h;
	int			z_ui;
}	t_game;

#endif
