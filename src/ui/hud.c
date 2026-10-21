/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*hud_text(t_game *g, mlx_image_t *old, char *s, int y)
{
	mlx_image_t	*img;

	if (old)
		mlx_delete_image(get_mlx(), old);
	img = mlx_put_string(get_mlx(), s, 24, y);
	if (!img)
		exit_error("Failed to draw HUD text");
	mlx_set_instance_depth(&img->instances[0], g->z_ui);
	return (img);
}

/* compteur de coups, champignons restants et niveau courant */
void	hud_refresh(t_game *g)
{
	t_data_map	*l;
	char		*s;

	l = cur_lvl(g);
	s = ft_strjoin("Coups : ", ft_itoa(l->player->move_count));
	l->hud.moves = hud_text(g, l->hud.moves, s, 10);
	s = ft_strjoin3("Champignons : ",
			ft_itoa(l->map->total_collect - l->map->info->collectibles),
			ft_strjoin("/", ft_itoa(l->map->total_collect)));
	l->hud.items = hud_text(g, l->hud.items, s, 32);
	s = ft_strjoin3(ft_strjoin("Niveau ", ft_itoa(g->i_game + 1)),
			"/", ft_itoa(g->flag->ndmap));
	if (!l->hud.level)
		l->hud.level = hud_text(g, NULL, s, 54);
}

void	hud_delete(t_game *g)
{
	t_hud	*h;

	h = &cur_lvl(g)->hud;
	if (h->moves)
		mlx_delete_image(get_mlx(), h->moves);
	if (h->items)
		mlx_delete_image(get_mlx(), h->items);
	if (h->level)
		mlx_delete_image(get_mlx(), h->level);
	*h = (t_hud){NULL, NULL, NULL};
}
