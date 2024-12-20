/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:35:15 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 20:57:45 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_enemy	*init_enemy(int x, int y)
{
	t_enemy	*enemy;

	enemy = ft_arnalloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->nb = 0;
	enemy->position = init_point();
	if (!enemy->position)
		return (NULL);
	enemy->position->x = x;
	enemy->position->y = y;
	enemy->sprite = init_sprite();
	return (enemy);
}


void	set_instance_coordinates(mlx_image_t *sprite, int t,
			t_point *point, int z)
{
	sprite->instances[t].x = (point->x * TILE_SIZE);
	sprite->instances[t].y = (point->y * TILE_SIZE);
	if (z)
		sprite->instances[t].z = z;
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	static int	move_x = 1;

	if (game->map->map_data[enemy->position->x + move_x] \
	[enemy->position->y ] != WAll)
	{
		game->map->map_data[enemy->position->y][enemy->position->x] = VOID;
		enemy->position->x += move_x;
		game->map->map_data[enemy->position->y][enemy->position->x] = ENEMY;
	}
	else
		move_x *= -1;
}



void	set_enemy(t_game *game, t_enemy *enemy, int nb)
{
	if (enemy->sprite->sprite)
	{
		mlx_delete_image(game->window->mlx_instance, enemy->sprite->sprite);
		enemy->sprite->sprite = NULL;
		enemy->sprite->id = -1;
	}
	set_tile(game, enemy->sprite, enemy->position, PATH_SPRITE_ENEMY);
	set_instance_coordinates(enemy->sprite->sprite, nb, enemy->position, \
	Z_DEFAULT_ENEMY);
}


void	enemys_move(t_game *game)
{
	t_enemy	*enemy;
	int		i;

	i = 0;

	while (i < game->map->info->enemys)
	{
		enemy = game->enemy[i];
		move_enemy(game, enemy);
		if (enemy->position->x == game->player->position->x && \
			enemy->position->y == game->player->position->y)
			game->player->health_points--;
		set_enemy(game, enemy, i);
		i++;
	}
}

int	cote_enemy(t_game *game)
{
	int		cote;
	t_point	*p;
	
	p = init_point();
	cote = 0;
	while(p->y < game->map->height)
	{
		p->x = 0;
		while(p->x < game->map->width)
		{
			if (game->map->map_data[p->y][p->x] == ENEMY)
				cote++;
			p->x++;
		}
		p->y++;
	}
	return (cote);
}
