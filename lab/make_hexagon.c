#include "mlx.h"
#include <stdio.h>

enum e_point
{
	X,
	Y,
	POINT_NUM,
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_straight_line(t_data *img, int *src_point, int *dst_point)
{
	int x;
	int y;
	int	a;

	a = (dst_point[Y] - src_point[Y]) / (dst_point[X] - src_point[X]);
	x = src_point[X];
	while (x != dst_point[X])
	{
		y = a * (x - src_point[X]) + src_point[Y];
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		if (src_point[X] < dst_point[X])
			x++;
		else
			x--;
	}
}

void	make_hexagon(t_data *img, int center_x, int center_y, int to_point)
{
	int		points[7][POINT_NUM];
	int		center[POINT_NUM];
	int		i;

	center[X] = center_x;
	center[Y] = center_y;
	points[0][X] = center[X] + to_point;
	points[0][Y] = center[Y];
	points[1][X] = center[X] + (to_point / 2);
	points[1][Y] = center[Y] - to_point;
	points[2][X] = center[X] - (to_point / 2);
	points[2][Y] = center[Y] - to_point;
	points[3][X] = center[X] - to_point;
	points[3][Y] = center[Y];
	points[4][X] = center[X] - (to_point / 2);
	points[4][Y] = center[Y] + to_point;
	points[5][X] = center[X] + (to_point / 2);
	points[5][Y] = center[Y] + to_point;
	points[6][X] = -1;
	points[6][Y] = -1;
	i = 0;
	while (1)
	{
		if (points[i + 1][X] == -1)
		{
			make_straight_line(img, points[i], points[0]);
			break ;
		}
		make_straight_line(img, points[i], points[i + 1]);
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
//	int		x;
//	int		mid;
//	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
/*
	x = 100;
	mid = 150;
	while (x <= 200)
	{
		if (x <= mid)
			y = (mid - x) * (mid - x) / 5;
		else
			y = (x - mid) * (x - mid) / 5;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
	}*/
	make_hexagon(&img, 250, 250, 100);
	make_hexagon(&img, 350, 350, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
