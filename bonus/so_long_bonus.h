/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:46:24 by rmarcas-          #+#    #+#             */
/*   Updated: 2025/02/28 16:49:31 by rmarcas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'
# define ENEMY			 	'T'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COINS_XPM			"assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"
# define ENEMY_XPM			"assets/sprites/enemy2.xpm"
# define ENEMY2_XPM			"assets/sprites/enemy2.xpm"

# define MAGENTA			"\033[1;35m"
# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	char		**copy;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_position	player;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win;
	int		movements;
	int		player_sprite;
	t_map	map;
	t_bool	map_alloc;
	t_image	wall;
	t_image	floor;
	t_image	coins;
	t_image	open_exit;
	t_image	exit_closed;
	t_image	player_front;
	t_image	player_back;
	t_image	player_left;
	t_image	player_right;
	t_image	enemy;
}	t_game;

void	ft_check_map(t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_verify_parameters(t_game *game);
void	ft_check_arguments(int argc, char **argv, t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_parameters(t_game *game);
int		ft_error_msg(char *message, t_game *game);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	ft_empty_line(char *map, t_game *game);
void	ft_free_map(t_game *game);
void	ft_init_sprites(t_game *game);
int		ft_render_map(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
int		ft_close_game(t_game *game);
void	ft_destroy_images(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
int		ft_victory(t_game *game);
void	ft_verify_win(t_game *game, char *argv);
/************************** BONUS ******************************/
int		ft_loss(t_game *game);
#endif
