#include "so_long.h"

void ft_init_vars(t_game *game)
{
    game -> map -> coins = 0;
    game -> map -> exit = 0;
    game -> map -> players = 0;
    game -> movements = 0;
    game -> map -> columns = ft_strlen(game -> map -> full[0]) - 1;
    game -> player_sprite = RIGHT;
}

void ft_init_mlx (t_game *game)
{
    game ->mlx_ptr = mlx_init();
    if (game -> mlx_ptr == NULL)
    {
        free(game -> mlx_ptr);
        ft_error_msg("Could't find mlx pointer.",game);
    }
    game -> win_ptr = mlx_new_window(game ->mlx_ptr, \
    game -> map -> columns * IMG_WIDTH, game -> map -> rows * IMG_HEIGHT, "ventana so_long");
    if(game -> mlx_ptr == NULL)
    {
        free(game ->mlx_ptr);
        ft_error_msg("Could't create the window.",game);
    }
}

/*void ft_init_sprites(t_game *game)
{
    void    *mlx;

    mlx = game -> mlx_ptr;
    game -> wall ft_new_sprite(mlx, WALL_XPM, game);
    game -> floor ft_new_sprite(mlx, FLOOR_XPM, game);
    game -> coins;
    game -> player_front;
    game -> player_back;
    game -> player_left;
    game -> player_rigth;
    game -> open_exit;
    game -> exit_closed;
}

t_image ft_new_sprite(void *mlx, chat *path, t_game *game)
{
    t_image sprite;

    //mlx_xmp_file_to_image(mlx, relative_path, &img_width, &img_height)
    sprite.xpm_ptr = mlx_xmp_file_to_image(mlx, path, &sprite.x, &sprite.y);
    if (sprite.xmp_ptr == NULL)
        ft_error_msg("Could't find a sprite. Does it exist?.",game);
    return (sprite);
}*/

