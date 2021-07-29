#include "mlx.h"
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
	PANEL_NUM,
};

enum	e_coordinates
{
	X,
	Y,
	COOR_NUM,
};

enum	e_collectibles
{
	NOW,
	MAX,
	COLL_NUM,
};

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img[PANEL_NUM];
	int		img_length[COOR_NUM];
	int		panel_cnt[COOR_NUM];
	int		p_posit[COOR_NUM];
	int		coll_cnt[COLL_NUM];
	int		**map;
}				t_data;

void	initialize_data(t_data *data)
{
	data->mlx = mlx_init();
	data->img[EMPTY] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/forest.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[WALL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/tree.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[COLL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/old-man.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EXIT] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/escape.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[PLAYER] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/monster.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->mlx_win = mlx_new_window(data->mlx, \
		data->panel_cnt[X] * data->img_length[X], data->panel_cnt[Y] * data->img_length[Y], "Hello world!");
	data->coll_cnt[NOW] = 0;
}

void	free_2d_array(int **array, int until)
{
	while (--until >= 0)
		free(array[until]);
	free(array);
}

void	ft_exit(int fd, char *line, t_data *data, int until)
{
	int status;

	free(line);
	status == 1;
	while (status == 1)
	{
		status = get_next_line(0, &line);
		free(line);
	}
	free_2d_array(data->map, until);
	exit(1);
}

void	destroy_all_images(t_data *data)
{
	int i;

	i = -1;
	while (++i < PANEL_NUM)
		mlx_destroy_image(data->mlx, data->img[i]);
}

void	put_2d_array(t_data *data)
{
	int	x;
	int y;

	x = -1;
	while (++x < data->panel_cnt[X])
	{
		y = -1;
		while (++y < data->panel_cnt[Y])
			printf("(%d, %d)->%d\n", x, y, data->map[x][y]);
	}
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_all_images(data);
	mlx_destroy_display(data->mlx);
	free_2d_array(data->map, data->panel_cnt[X]);
	free(data->mlx);
	exit(0);
	return (0);
}

void	create_map(t_data *data)
{
	int	x;
	int	y;

//	mlx_clear_window(data->mlx, data->mlx_win);
	x = -1;
	while (++x < data->panel_cnt[X])
	{
		y = -1;
		while (++y < data->panel_cnt[Y])
		{
			mlx_put_image_to_window\
			(data->mlx, data->mlx_win, data->img[data->map[x][y]], \
			x * data->img_length[X], y * data->img_length[Y]);
		}
	}
}

void	move_next_or_not(int next_x, int next_y, t_data *data)
{
	if (next_x < 0 || data->panel_cnt[X] - 1 < next_x || next_y < 0 || data->panel_cnt[Y] - 1 < next_y)
		return ;
	if (data->map[next_x][next_y] == WALL)
		return ;
	if (data->map[next_x][next_y] == EXIT)
	{
		if (data->coll_cnt[NOW] == data->coll_cnt[MAX])
			close_win(data);
		else
			return ;
	}
	if (data->map[next_x][next_y] == COLL)
		data->coll_cnt[NOW]++;
	data->map[data->p_posit[X]][data->p_posit[Y]] = EMPTY;
	data->map[next_x][next_y] = PLAYER;
	data->p_posit[X] = next_x;
	data->p_posit[Y] = next_y;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == LEFT)
		move_next_or_not(data->p_posit[X] - 1, data->p_posit[Y], data);
	if (keycode == RIGHT)
		move_next_or_not(data->p_posit[X] + 1, data->p_posit[Y], data);
	if (keycode == UP)
		move_next_or_not(data->p_posit[X], data->p_posit[Y] - 1, data);
	if (keycode == DOWN)
		move_next_or_not(data->p_posit[X], data->p_posit[Y] + 1, data);
	if (keycode == ESC)
		close_win(data);
	create_map(data);
	return (keycode);
}

void	make_2d_array(t_data *data)
{
	int	x;
	int	y;

	data->panel_cnt[X] = 10;
	data->panel_cnt[Y] = 10;
	data->map = (int **)malloc(sizeof(int *) * data->panel_cnt[X]);
	if (!data->map)
		exit(1);
	x = -1;
	while (++x < data->panel_cnt[X])
	{
		data->map[x] = (int *)malloc(sizeof(int) * data->panel_cnt[Y]);
		if (!data->map[x])
		{
			free_2d_array(data->map, x);
			exit (1);
		}
		y = -1;
		while (++y < data->panel_cnt[Y])
			data->map[x][y] = EMPTY;
	}
	data->p_posit[X] = 0;
	data->p_posit[Y] = 0;
	data->map[data->p_posit[X]][data->p_posit[Y]] = PLAYER;
	data->map[3][3] = COLL;
	data->map[5][5] = COLL;
	data->map[8][8] = COLL;
	data->map[7][7] = WALL;
	data->map[9][7] = WALL;
	data->map[4][7] = EXIT;
	data->coll_cnt[MAX] = 3;
}

int	main(void)
{
	t_data	data;

	make_2d_array(&data);
	initialize_data(&data);
	create_map(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 33, 1L << 17, close_win, &data);
	mlx_loop(data.mlx);
}
