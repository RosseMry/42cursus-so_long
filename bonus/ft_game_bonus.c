/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:53:42 by rmarcas-          #+#    #+#             */
/*   Updated: 2025/04/04 19:27:57 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_init_var_2(t_game *game)
{
	game ->map . columns = ft_strlen(game -> map . full[0]) - 1;
	game -> map . coins = 0;
	game -> map . exit = 0;
	game -> map . players = 0;
	game -> movements = 0;
	game -> player_sprite = RIGHT;
}

void	ft_init_vars(t_game *game)
{
	if (game->map.full == NULL || ft_strlen(game->map.full[0]) < 1)
		ft_error_msg("No map", game);
	else
		ft_init_var_2(game);
}

void	ft_init_mlx(t_game *game)
{
	game ->mlx_ptr = mlx_init();
	if (game -> mlx_ptr == NULL)
	{
		free(game -> mlx_ptr);
		ft_error_msg("Could't find mlx pointer.", game);
	}
	game -> win = mlx_new_window(game ->mlx_ptr, \
	game ->map.columns * IMG_WIDTH, \
	game ->map . rows * IMG_HEIGHT, "ventana so_long");
	if (game ->win == NULL)
	{
		free(game ->mlx_ptr);
		ft_error_msg("Could't create the window.", game);
	}
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Could't find a sprite. Does it exist?.", game);
	return (sprite);
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->coins = ft_new_sprite(mlx, COINS_XPM, game);
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
	game->enemy = ft_new_sprite(mlx, ENEMY_XPM, game);
}
