NAME			= so_long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC 				= clang

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -Lmlx -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f


BONUS_SRCS_DIR	= ./bonus_sources/

SRCS			= so_long.c			\
				ft_check_map.c		\
				ft_game.c		\
				ft_map.c		\
				ft_libft_utils.c\
				get_next_line.c\
				get_next_line_utils.c\
				ft_close.c\
				ft_free_memory.c

all:			${NAME}

${NAME}: 		
				${CC} ${SRCS} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

clean:
				make clean -C
				@echo

fclean:
				${REMOVE} ${NAME}
				@echo "${NAME}: ${RED}${NAME} were deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber


.PHONY:			all clean fclean re