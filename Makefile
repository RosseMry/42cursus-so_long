NAME			= so_long
NAME_BONUS		= so_long_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libft/libft.a
CC 				= gcc

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g3
MINILIBX_FLAGS	= -Lmlx -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

BONUS_SRCS_DIR	= bonus/

SRCS			= so_long.c			\
				ft_check_map.c		\
				ft_game.c		\
				ft_map.c		\
				get_next_line.c\
				ft_close.c\
				ft_free_memory.c\
				ft_input.c\
				ft_floodfill.c\
				ft_render.c


SRCS_BONUS 		= $(addprefix $(BONUS_SRCS_DIR),\
				so_long_bonus.c				\
				ft_check_map_bonus.c		\
				ft_close_bonus.c		\
				ft_free_memory_bonus.c		\
				get_next_line_bonus.c\
				ft_input_bonus.c		\
				ft_game_bonus.c		\
				ft_map_bonus.c			\
				ft_floodfill_bonus.c \
				ft_render_bonus.c)

all:			${LIBFT} ${NAME}

${NAME}: 		
				@make -C $(MLX_PATH) all
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

bonus:			${LIBFT} ${NAME_BONUS}

${NAME_BONUS}: 	
				@make -C $(MLX_PATH) all	
				${CC} ${SRCS_BONUS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME_BONUS}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C libft

clean:
				make clean -C libft
				make -C $(MLX_PATH) clean
				make clean -C
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

re:				fclean all

rebonus:		fclean ${NAME_BONUS}

.PHONY:			all clean fclean re rebonus valgrind

