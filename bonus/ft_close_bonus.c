#include "so_long_bonus.h"

int	ft_victory(t_game *game)
{
    ft_putstr("victoria");
	ft_free_all_allocated_memory(game);
	exit (EXIT_FAILURE);
}
int	ft_loss(t_game *game)
{
    ft_putstr("perdiste");
	ft_free_all_allocated_memory(game);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_free_all_allocated_memory(game);
	exit (EXIT_FAILURE);
}

int ft_error_msg(char *message, t_game *game)
{
    if(game -> map_alloc == true)
        ft_free_map(game);
    free(game);
    ft_putstr(message);
    exit(1);
}