/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:47:03 by max_dev           #+#    #+#             */
/*   Updated: 2024/12/12 17:23:17 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include "so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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

typedef struct s_map
{
	char		**map_data;
	int			width;
	int			height;
	mlx_image_t	*sprite_void;
	mlx_image_t	*sprite_wall;
	mlx_image_t	*sprite_exit;
	mlx_image_t	*sprite_collect;
	mlx_image_t	*sprite_wotre;
	t_map_info	*info;
}	t_map;

typedef struct s_player
{
	t_point		*position;
	int			move_count;
	int			health_points;
	mlx_image_t	*sprite;
}	t_player;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
}	t_game;


#endif
