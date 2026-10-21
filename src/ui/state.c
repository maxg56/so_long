/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*moves_str(t_game *g)
{
	return (ft_strjoin("Coups : ", ft_itoa(cur_lvl(g)->player->move_count)));
}

static void	show_end(t_game *g, t_state st)
{
	char	*l[4];

	l[2] = "[R] Recommencer      [Echap] Quitter";
	l[3] = NULL;
	if (st == ST_GAME_OVER)
	{
		l[0] = "GAME OVER - partie abandonnee";
		l[1] = moves_str(g);
	}
	else
	{
		l[0] = "VICTOIRE ! Tous les niveaux sont finis";
		l[1] = moves_str(g);
	}
	overlay_show(g, l);
}

/* change d'etat et affiche l'ecran correspondant */
void	set_state(t_game *g, t_state st)
{
	char	*l[4];

	g->state = st;
	l[3] = NULL;
	if (st == ST_PLAY)
		overlay_hide(g);
	else if (st == ST_PAUSE)
	{
		l[0] = "PAUSE";
		l[1] = "Abandonner la partie ?";
		l[2] = "[O/Y] Oui      [N/Echap] Non";
		overlay_show(g, l);
	}
	else if (st == ST_LEVEL_DONE)
	{
		l[0] = "NIVEAU TERMINE !";
		l[1] = moves_str(g);
		l[2] = "[Entree] Niveau suivant";
		overlay_show(g, l);
	}
	else
		show_end(g, st);
}
