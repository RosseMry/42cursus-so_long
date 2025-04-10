/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:06:55 by rmarcas-          #+#    #+#             */
/*   Updated: 2025/04/01 11:25:48 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clean(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.rows)
	{
		free(game->map.copy[string++]);
	}
	free(game->map.copy);
}

static void	ft_copy(t_game *game, char *argv)
{
	char	*map_tmp;
	char	*line_tmp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened.Does the Map exist?", game);
	map_tmp = ft_strdup("");
	while (true)
	{
		line_tmp = get_next_line(map_fd);
		if (line_tmp == NULL)
			break ;
		map_tmp = ft_strappend(&map_tmp, line_tmp);
		free(line_tmp);
	}
	close(map_fd);
	ft_empty_line(map_tmp, game);
	game->map.copy = ft_split(map_tmp, '\n' );
	free(map_tmp);
}

void	flood_fill(t_game *game, char **copie, int x, int y)
{
	if (x < 0 || y < 0 || y >= game-> map.rows || x >= game -> map.columns \
	|| copie[y][x] == '1' || copie[y][x] == 'X')
		return ;
	copie[y][x] = 'X';
	flood_fill(game, copie, x + 1, y);
	flood_fill(game, copie, x - 1, y);
	flood_fill(game, copie, x, y + 1);
	flood_fill(game, copie, x, y - 1);
}

void	ft_verify_win(t_game *game, char *argv)
{
	int		can_row;
	int		can_colun;

	can_row = 0;
	ft_copy(game, argv);
	flood_fill(game, game -> map.copy, game -> map.player.x, \
	game -> map.player.y);
	while (can_row < game->map.rows)
	{
		can_colun = 0;
		while (can_colun < game->map.columns)
		{
			if (game->map.copy[can_row][can_colun] == '0' \
			|| game->map.copy[can_row][can_colun] == 'E' \
			|| game->map.copy[can_row][can_colun] == 'C')
			{
				ft_error_msg("There is no posible way to win", game);
				return ;
			}
			can_colun++;
		}
		can_row++;
	}
	ft_clean(game);
}
