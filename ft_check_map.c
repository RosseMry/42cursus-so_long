#include "so_long.h"

void ft_check_map(t_game *game)
{
    ft_check_rows(game);
    ft_check_columns(game);
    ft_count_parameters(game);
    ft_verify_parameters(game);
}

void ft_check_rows(t_game *game)
{
    int i;
    i = 0;
    while (i < game -> map -> rows)
    {
        if ( game -> map -> full[i][0] != WALL)
            ft_error_msg("Invalid Map, There's a wall missing on the first row",game);
        else if (game -> map -> full[i][game -> map -> columns - 1] != WALL)
            ft_error_msg("Invalid Map, The map must be surrounded by walls",game);
        i++;
    }
}
void ft_check_columns(t_game *game)
{
    int i;
    i = 0;
    while (i< game -> map -> columns)
    {
        if (game -> map -> full[0][i] != WALL)
            ft_error_msg("Invalid Map, There's a wall missing in the first column",game);
        else if (game -> map -> full [game -> map -> rows - 1][i] != WALL)
            ft_error_msg("Invalid Map, The map must be surrounded by walls! :c ",game);
        i++;
    }
}

void ft_count_parameters(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(y < game -> map -> columns)
    {
        x = 0;
        while (x < game -> map -> rows) //doble para verificar en todo el mapa
        {
            if(!ft_strchr("CEP01", game -> map -> full[y][x])) // porque yx y no xy porque el puse x vertical y y horizontal
                ft_error_msg("Invalid Map, Not expected map parameter",game);
            else if(game -> map -> full[y][x])
            {
                game -> map -> players++;
                game -> map -> player.x = x;
                game -> map -> player.y = y; 
            }
            else if (game -> map -> full[y][x] == COINS)
                game -> map -> coins++;
            else if (game -> map -> full[y][x] == MAP_EXIT)
                game -> map -> exit++;
            x++;
        }
        y++;
    }
}
//si es necesario luego agrego el map entrada si hay 1 o mas de 1 en la linea 57
void ft_verify_parameters(t_game *game)
{
    if(game -> map -> coins == 0)
        ft_error_msg("Invalid Map, There are no coins",game);
    else if (game -> map -> exit != 1) // el ejemplo lo tiene como == 0
        ft_error_msg("Invalid Map, There is not exit or more than 1" , game);
    else if (game -> map -> players != 1)
        ft_error_msg("Invalid Map, Invalid player quantity", game);
}



