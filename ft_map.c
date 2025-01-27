#include "so_long.h"

void ft_check_arguments(int argc, char **argv, t_game *game)
{
    int map_len;
    game -> map_alloc = false;
    if (argc > 2)
        ft_error_msg("Too many arguments.",game);
    if (argc < 2)
        ft_error_msg("The Map file is missing.",game);
    map_len = ft_strlen(argv[1]);
    //verificar si el archivo map es .ber
    if(!ft_strnstr(&argv[1][map_len - 4],".ber",4))
    {
        ft_error_msg("Map file extension is wrong",game);
    }
}
void    ft_init_map(t_game *game, char *argv)
{
    char    *map_tmp;
    char    *line_tmp;
    int map_fd;

    map_fd = open(argv,O_RDONLY);
    if(map_fd == -1)
       ft_error_msg("The Map couldn't be opened. Does the Map exist?",game);
    map_tmp = ft_strdup(""); // rellenando con un espacio para q no tenga 0 c: 
    game->map.rows = 0; //inicializando en 0 filas
    while (true) // bucle infinito solo termina con el break
    {
        line_tmp = get_next_line(map_fd);
        if(line_tmp == NULL)
            break; //Aqui termina xq ya no hay mas lineas
        map_tmp = ft_strappend(&map_tmp, line_tmp);
        free(line_tmp);
        game->map.rows++;
    }
    close(map_fd);
    ft_empty_line(map_tmp, game);//funcion para ver lineas vacias ft_empty_line
    game->map.full = ft_split(map_tmp, '\n' );
    game -> map_alloc = true;
    free(map_tmp);

}

void ft_empty_line (char *map, t_game *game)
{
    int i;
    i = 0;
    if(map[0] == '\n')
    {
        free(map);
        ft_error_msg("Invalid Map. The map have an empty line at the beginning.",game);
    }
    else if(map[ft_strlen(map) - 1]=='\n')
    {
        free(map);
        ft_error_msg("Invalid Map. The map have an empty line at the end.",game);
    }
    while(map[i+1])
    {
        if(map[i] == '\n' && map[i+1] == '\n')
        {
            free(map);
            ft_error_msg("Invalid Map. The map have an empty line in the middle.",game);
        }
        i++;
    }
}

