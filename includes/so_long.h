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

enum	e_panel_of_map
{
	EMPTY,
	WALL,
	COLL,
	EXIT,
	PLAYER,
	ENEMY,
	PANEL_NUM,
};

enum	e_coordinates
{
	X,
	Y,
	COOR_NUM,
};

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img[PANEL_NUM];
	int		img_length[COOR_NUM];
	int		panel_num[COOR_NUM];
	int		panel_cnt[PANEL_NUM];
	int		p_posit[COOR_NUM];
	int		e_posit[COOR_NUM];
	int		move_cnt;
	int		enemy_moving;
	int		**map;
}				t_data;

#endif
