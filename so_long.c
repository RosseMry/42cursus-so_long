#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  *game;
    game = malloc(sizeof(t_game));
    ft_check_arguments(argc,argv,game);
    ft_init_map(game, argv[1]);
    ft_init_vars(game);
    ft_check_map(game);
    ft_init_mlx(game);
    
}