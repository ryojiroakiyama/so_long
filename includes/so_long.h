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

#endif
