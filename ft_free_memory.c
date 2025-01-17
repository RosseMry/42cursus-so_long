#include "so_long.h"

void ft_free_map(t_game *game)
{
    int string;
    string = 0;
    while (string < game->map->rows)
        free(game -> map -> full[string++]);
    free(game -> map -> full);
}