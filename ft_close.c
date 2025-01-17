#include "so_long.h"

int ft_error_msg(char *message, t_game *game)
{
    if(game -> map_alloc == true)
        ft_free_map(game);
    if (!message)
        write(1,"no mensaje",10);
    free(game);
    write(1,"mensaje",7); //USAR EL PRINTF LUEGO
    exit(1);
}