NAME = so_long

NAME_BONUS = so_long_bonus

SRCS_DIR = ./srcs/

SRCS_NAME = main.c initialization.c \
			get_map.c get_map_utils.c \
			set_mlx_data.c set_mlx_image.c \
			event_occurrence.c loop.c exit.c \
			get_next_line.c get_next_line_utils.c

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

SRCS_BONUS_DIR = ./srcs_bonus/

SRCS_BONUS_NAME = main_bonus.c initialization_bonus.c \
				get_map_bonus.c get_map_utils_bonus.c \
				set_mlx_data_bonus.c set_mlx_image1_bonus.c set_mlx_image2_bonus.c \
				event_occurrence_bonus.c change_map_utils_bonus.c \
				loop_bonus.c exit_bonus.c \
				get_next_line_bonus.c get_next_line_utils_bonus.c

SRCS_BONUS = ${addprefix ${SRCS_BONUS_DIR}, ${SRCS_BONUS_NAME}}

HEADER = ./includes

LIBFT_DIR = ./libft

MLX_DIR = ./minilibx-linux

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ${MLX_DIR} -I ${HEADER} -I ${LIBFT_DIR}

RM = rm -rf

all: ${NAME}

bonus: ${NAME_BONUS}

${NAME}: ${MLX_DIR} ${OBJS} ${HEADER} ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@${MAKE} -C ${LIBFT_DIR}
	${CC} ${C_FLAGS} -o ${NAME} ${OBJS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

${NAME_BONUS}: ${MLX_DIR} ${OBJS_BONUS} ${HEADER} ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@${MAKE} -C ${LIBFT_DIR}
	${CC} ${C_FLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

${MLX_DIR}:
	git clone https://github.com/42Paris/minilibx-linux.git ${MLX_DIR}

val:
	valgrind --leak-check=full -s --show-leak-kinds=all ./${NAME} ${map}

val_bonus:
	valgrind --leak-check=full -s --show-leak-kinds=all ./${NAME_BONUS} ${map}

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${NAME} ${NAME_BONUS} ${MLX_DIR}

re: fclean all

.PHONY: all bonus val val_bonus clean fclean re
