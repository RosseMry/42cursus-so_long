#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
#include <fcntl.h> //manipulate files
# include <X11/X.h>
# include <X11/keysym.h>

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

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
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_position	player;
}	t_map;

typedef struct  s_data
{
    void    *mlx_ptr; //MXL Pointer
    void    *win_ptr; //MLX window pointer
    void    *textures[5]; //MXL image pointers (keep on stack)
    int movements;
    int player_sprite;
    t_map   *map; //Map pointer (keep on stack)
    t_bool   map_alloc;
    t_image wall;
    t_image floor;
    t_image coins;
    t_image player_front;
    t_image player_back;
    t_image player_left;
    t_image player_rigth;
}   t_game;

void ft_check_map(t_game *game);
void    ft_init_map(t_game *game, char *argv);
void ft_init_vars(t_game *game);
void ft_init_mlx (t_game *game);
void ft_verify_parameters(t_game *game);
void ft_check_arguments(int argc, char **argv, t_game *game);
void ft_check_rows(t_game *game);
void ft_check_columns(t_game *game);
void ft_count_parameters(t_game *game);
int ft_error_msg(char *message, t_game *game);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strrchr(const char *str, int c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
void ft_empty_line (char *map, t_game *game);
void ft_free_map(t_game *game);
char	*ft_strappend(char **s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
#endif