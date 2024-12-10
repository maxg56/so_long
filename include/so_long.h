/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:30 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/10 10:45:47 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h> 

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define PATH_SPRITE_PLAYER "assets/player.xpm"
# define PATH_SPRITE_MUR "assets/mur.xpm"
# define PATH_SPRITE_EXIT "assets/exit.xpm"
# define PATH_SPRITE_COLLECT "assets/collect.xpm"

# define PLAYER 'P'
# define MUR '1'
# define EXIT 'E'
# define COLLECT 'C'
# define VIDE '0'

typedef struct s_vex
{
	int	x;
	int	y;
}	t_vex;

typedef struct s_stack
{
	t_vex			*vex;
	struct s_stack	*next;
}	t_stack;
typedef struct s_map_info
{
	t_bool	player;
	t_bool	exit;
	int		collect;
}	t_map_info;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*title;
}	t_window;

typedef struct s_map
{
	const char	**map;
	int			width;
	int			height;
	void		*sprat_void;
	void		*sprat_mur;
	void		*sprat_exit;
	t_map_info	*info;
}	t_map;

typedef struct s_player
{
	t_vex	*pos;
	int		moves;
	int		pv;
	void	*sprite;
}	t_player;

typedef struct s_game
{
	t_window	*window;
	t_map		*maps;
	t_player	*player;
}	t_game;

t_window	*init_window(char *title, int width, int height);
t_map		*init_map(void);
t_player	*init_player(int x, int y, void *sprite);
t_game		*init_game(void);
t_map_info	*init_val(void);

t_bool		parse_input(int ac, char **av, t_game *game);
t_bool		check_map_vide(t_game *game);

//utils_stack

t_stack		*ft_stacknew(int x, int y);
void		ft_stackadd(t_stack **stak, t_stack *new);
t_vex		*ft_stackget_back(t_stack **stack);

char		**mapcpy(char **map, int height);

// free

void		free_map(t_map *map);
void		free_game(t_game *game);
void		free_map_info(t_map_info *val);
void		free_tab(char **tab);
void		free_stack(t_stack *stack);

#endif