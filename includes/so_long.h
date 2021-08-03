#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define LEFT 97
#define UP 119
#define RIGHT 100
#define DOWN 115
#define ESC 65307

enum	e_square
{
	EMPTY,
	WALL,
	COLL,
	EXIT,
	PLAYER,
	SQUARE_NUM
};

enum	e_coordinates
{
	X,
	Y,
	COOR_NUM
};

enum	e_side
{
	FRONT_SIDE,
	RIGHT_SIDE,
	BUCK_SIDE,
	LEFT_SIDE,
	SIDE_NUM
};

enum	e_action
{
	ACTION1,
	ACTION2,
	ACTION3,
	ACTION4,
	ACTION_NUM
};

enum	e_status
{
	NORMAL,
	ABNORMAL,
	SYSERROR,
	STATUS_NUM
};


typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img[SQUARE_NUM][SIDE_NUM][ACTION_NUM];
	int		square_side[SQUARE_NUM];
	int		square_act[SQUARE_NUM];
	int		square_len[COOR_NUM];
	int		square_num[COOR_NUM];
	int		type_cnt[SQUARE_NUM];
	int		posit[SQUARE_NUM][COOR_NUM];
	int		move_cnt;
	int		**map;
}				t_data;

int		main(int ac, char **av);
void	init_array_zero(int *array, int size);
void	init_img(t_data *data);
void	init_data(t_data *data);
int		read_map(char *map_path, t_data *data);
void	set_map(char *map_path, t_data *data);
int		check_map(t_data *data);
int		is_error(int result, char *s, t_data *data);
int		is_square(char c);
int		**malloc_2d_array(int size1, int size2);
void	*is_null(void *result, char *s, t_data *data);
void	set_mlx_data(t_data *data);
void	set_empty_img(t_data *data);
void	set_wall_img(t_data *data);
void	set_coll_img(t_data *data);
void	set_exit_img(t_data *data);
void	set_player_img(t_data *data);
void	print_info(t_data *data);
int		get_next_posit(int *now, int *next, int direction, t_data *data);
void	move_to_empty(int who, int *next, t_data *data);
int		key_hook(int keycode, t_data *data);
int		click_red_cross(t_data *data);
void	put_map(t_data *data);
void	run_animation(t_data *data);
int		loop_func(t_data *data);
void	free_2d_array(int **array, int until);
void	destroy_all_images(t_data *data);
int		ft_exit(int status, char *s, t_data *data);

#endif
