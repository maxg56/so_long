/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:00:00 by mgendrot          #+#    #+#             */
/*   Updated: 2026/10/21 10:00:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/* geometrie isometrique (en pixels) */
# define TILE_W 96
# define TILE_H 48
# define WALL_H 30
# define LEDGE_H 10
# define EXIT_H 72

/* fenetre */
# define WIN_MIN_W 800
# define WIN_MIN_H 600
# define WIN_MAX_W 1920
# define WIN_MAX_H 1080
# define HUD_H 70
# define MARGIN 48
# define TOP_ROOM 110

/* feuille de sprites du joueur (Warrior_Purple.png) */
# define FRAME_SZ 192
# define SHEET_COLS 6
# define ROW_IDLE 0
# define ROW_RUN 1
# define ANCHOR_X 96
# define ANCHOR_Y 132
# define FRAME_TIME 0.09

/* timings des animations (secondes) */
# define MOVE_TIME 0.16
# define POP_TIME 0.30
# define EXIT_FRAMES 6
# define EXIT_FRAME_TIME 0.08
# define FADE_TIME 0.25
# define CAM_SPEED 8.0

/* overlay */
# define PANEL_W 560
# define PANEL_H 200
# define OV_LINES 4

/* assets */
# define PATH_SHEET "assets/img/Warrior_Purple.png"
# define PATH_GRASS "assets/img/Tilemap_Flat.png"
# define PATH_STONE "assets/img/Tilemap_Elevation.png"
# define PATH_COLLECT "assets/collect.png"
# define PATH_DEFAULT_MAP "maps/p1.ber"

#endif
