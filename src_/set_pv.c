

void	set_pv(t_game *game)
{
	char		*pv;
	static int	pv_leve = 4;

	if (game->player->health_points != pv_leve)
	{
		pv_leve = game->player->health_points;
		pv = ft_strjoin("pv : ", ft_itoa(game->player->health_points));
		if (game->sprite_pv)
			mlx_delete_image(game->window->mlx_instance, game->sprite_pv);
		game->sprite_pv = mlx_put_string(game->window->mlx_instance, \
		pv, TILE_SIZE + 50, 15);
		game->sprite_pv->instances[0].z = Z_DEFAULT_UI +1;

	}
}