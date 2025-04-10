/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:06:04 by rmarcas-          #+#    #+#             */
/*   Updated: 2025/04/04 19:20:52 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_files(void)
{
	if (open(WALL_XPM, O_RDONLY) <= 0 || open(FLOOR_XPM, O_RDONLY) <= 0 \
	|| open(COINS_XPM, O_RDONLY) <= 0 || open(PLAYER_FRONT_XPM, O_RDONLY) <= 0 \
	|| open(PLAYER_LEFT_XPM, O_RDONLY) <= 0 || \
	open(PLAYER_RIGHT_XPM, O_RDONLY) <= 0 \
	|| open(PLAYER_BACK_XPM, O_RDONLY) <= 0 || \
	open(OPEN_EXIT_XPM, O_RDONLY) <= 0 \
	|| open(EXIT_CLOSED_XPM, O_RDONLY) <= 0)
	{
		write(1, "Couldn't load exit_closed sprite\n", 33);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_check_files();
	game = malloc(sizeof(t_game));
	ft_check_arguments(argc, argv, game);
	ft_init_map(game, argv[1]);
	if (game->map.full == NULL || game->map.rows == 0)
		ft_error_msg("Map is empty or invalid.", game);
	ft_init_vars(game);
	ft_check_map(game);
	ft_verify_win(game, argv[1]);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_render_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, ft_close_game, game);
	mlx_hook(game->win, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_allocated_memory(game);
	return (0);
}
