#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364
#define ESC 65307

enum	e_piece_of_map
{
	EMPTY,
	WALL,
	COLL,
	EXIT,
	PLAYER,
	PIECE_NUM,
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
	void	*img[PIECE_NUM];
	int		img_width;
	int		img_height;
	int		w_cnt;
	int		h_cnt;
	int		player[COOR_NUM];
	int		**map;
}				t_data;

void	initialize_data(t_data *data)
{
	data->mlx = mlx_init();
	data->img[EMPTY] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/ship.xpm", &(data->img_width), &(data->img_height));
	data->img[WALL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/ship.xpm", &(data->img_width), &(data->img_height));
	data->img[COLL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/ship.xpm", &(data->img_width), &(data->img_height));
	data->img[EXIT] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/ship.xpm", &(data->img_width), &(data->img_height));
	data->img[PLAYER] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/ship02.xpm", &(data->img_width), &(data->img_height));
	data->mlx_win = mlx_new_window(data->mlx, \
		data->w_cnt * data->img_width, data->h_cnt * data->img_height, "Hello world!");
}

void	free_2d_array(int **array, int until)
{
	while (--until >= 0)
		free(array[until]);
	free(array);
}

void	destroy_img(t_data *data)
{
	int i;

	i = -1;
	while (++i < PIECE_NUM)
		mlx_destroy_image(data->mlx, data->img[i]);
}

void	put_2d_array(t_data *data)
{
	int	x;
	int y;

	x = -1;
	while (++x < data->w_cnt)
	{
		y = -1;
		while (++y < data->h_cnt)
			printf("(%d, %d)->%d\n", x, y, data->map[x][y]);
	}
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_img(data);
	mlx_destroy_display(data->mlx);
	free_2d_array(data->map, data->h_cnt);
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
	while (++x < data->w_cnt)
	{
		y = -1;
		while (++y < data->h_cnt)
		{
			mlx_put_image_to_window\
			(data->mlx, data->mlx_win, data->img[data->map[x][y]], \
			x * data->img_width, y * data->img_height);
		}
	}
	mlx_put_image_to_window\
	(data->mlx, data->mlx_win, data->img[PLAYER], \
	data->player[X] * data->img_width, data->player[Y] * data->img_height);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == LEFT && 0 < data->player[X])
		data->player[X]--;
	if (keycode == RIGHT && data->player[X] < data->w_cnt - 1)
		data->player[X]++;
	if (keycode == UP && 0 < data->player[Y])
		data->player[Y]--;
	if (keycode == DOWN && data->player[Y] < data->h_cnt - 1)
		data->player[Y]++;
	if (keycode == ESC)
		close_win(data);
	create_map(data);
	return (keycode);
}

void	make_2d_array(t_data *data)
{
	int	x;
	int	y;

	data->map = (int **)malloc(sizeof(int *) * data->w_cnt);
	if (!(data->map))
		exit(1);
	x = -1;
	while (++x < data->w_cnt)
	{
		(data->map)[x] = (int *)malloc(sizeof(int) * data->h_cnt);
		if (!(data->map)[x])
		{
			free_2d_array(data->map, x);
			exit (1);
		}
		y = -1;
		while (++y < data->h_cnt)
			(data->map)[x][y] = EMPTY;
	}
}

int	main(void)
{
	t_data	data;

	data.w_cnt = 5;
	data.h_cnt = 5;
	data.player[X] = 0;
	data.player[Y] = 0;
	make_2d_array(&data);
	initialize_data(&data);
	create_map(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 33, 1L << 17, close_win, &data);
	mlx_loop(data.mlx);
}
