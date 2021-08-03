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

RM = rm -f

all:
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@make ${NAME}

bonus:
	@${MAKE} -C ${LIBFT_DIR}
	@${MAKE} -C ${MLX_DIR}
	@make ${NAME_BONUS}

${NAME}: ${OBJS} ${MLX_DIR} ${HEADER} ${LIBFT_DIR}
	${CC} ${C_FLAGS} -o ${NAME} ${OBJS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

${NAME_BONUS}: ${OBJS_BONUS} ${MLX_DIR} ${HEADER} ${LIBFT_DIR}
	${CC} ${C_FLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} -L ${MLX_DIR} -lmlx -lXext -lX11 -L ${LIBFT_DIR} -lft

val:
	valgrind --leak-check=full -s --show-leak-kinds=all ./${NAME} ${map}

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all bonus val clean fclean re
