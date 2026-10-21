/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* centre (monde) d'une case : x vers bas-droite, y vers bas-gauche */
double	iso_wx(double x, double y)
{
	return ((x - y) * (TILE_W / 2));
}

double	iso_wy(double x, double y)
{
	return ((x + y) * (TILE_H / 2) + TILE_H / 2);
}

/*
 * Ordre de dessin : plus une case est "devant" (x + y), plus z est grand.
 * Layer -1 = sol, 0 = murs / objets, 1 = joueur. Deux images qui se
 * chevauchent ne doivent jamais avoir le meme z (test de profondeur GL).
 */
int	depth_of(int x, int y, int layer)
{
	return (1 + (x + y) * 3 + layer);
}

t_data_map	*cur_lvl(t_game *g)
{
	return (g->game[g->i_game]);
}
