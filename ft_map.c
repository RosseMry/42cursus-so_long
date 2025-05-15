/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:34:43 by rmarcas-          #+#    #+#             */
/*   Updated: 2025/04/04 19:29:09 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arguments(int argc, char **argv, t_game *game)
{
	int	map_len;

	game -> map_alloc = false;
	if (argc > 2)
		ft_error_msg("Too many arguments.", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	map_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
		ft_error_msg("Map file extension is wrong", game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_tmp;
	char	*line_tmp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened.Does the Map exist?", game);
	map_tmp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_tmp = get_next_line(map_fd);
		if (line_tmp == NULL)
			break ;
		map_tmp = ft_strappend(&map_tmp, line_tmp);
		free(line_tmp);
		game->map.rows++;
	}
	close(map_fd);
	ft_empty_line(map_tmp, game);
	game->map.full = ft_split(map_tmp, '\n');
	game -> map_alloc = true;
	free(map_tmp);
}

void	ft_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map == NULL || map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid Map o empty line at the beginning.", game);
	}
	else if (ft_strlen(map) != 0 && map[ft_strlen(map)] == '\n')
	{
		free(map);
		ft_error_msg("Invalid Map.Have an empty line at the end.", game);
	}
	while (map[i] && map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid Map.Have an empty line in the middle.", game);
		}
		i++;
	}
}
