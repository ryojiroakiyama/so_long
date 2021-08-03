NAME = so_long

NAME_BONUS = so_long_bonus

SRCS = ./srcs/main.c ./srcs_gnl/get_next_line.c ./srcs_gnl/get_next_line_utils.c

SRCS_BONUS = ./srcs_bonus/main_bonus.c

HEADER = ./includes

LIBFT_DIR = ./libft

MLX_DIR = ./minilibx-linux

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ${MLX_DIR} -I ${HEADER} -I ${LIBFT_DIR}

RM = rm -f

all:
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@make ${NAME}

${NAME}: ${OBJS} ${MLX_DIR} ${HEADER} ${LIBFT_DIR}
	${CC} ${C_FLAGS} -o ${NAME} ${OBJS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

val:
	valgrind --leak-check=full -s --show-leak-kinds=all ./${NAME} ${map}

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
