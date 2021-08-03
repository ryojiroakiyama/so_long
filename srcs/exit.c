#include "so_long.h"

void	free_2d_array(int **array, int until)
{
	if (array)
	{
		while (--until >= 0)
			free(array[until]);
		free(array);
	}
}

void	destroy_all_images(t_data *data)
{
	int	square;
	int	side;
	int	action;

	square = -1;
	while (++square < SQUARE_NUM)
	{
		side = -1;
		while (++side < SIDE_NUM)
		{
			action = -1;
			while (++action < ACTION_NUM)
			{
				if (data->img[square][side][action])
					mlx_destroy_image(data->mlx, \
						data->img[square][side][action]);
			}
		}
	}
}

int	ft_exit(int status, char *s, t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_all_images(data);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_2d_array(data->map, data->square_num[X]);
	if (data->mlx)
		free(data->mlx);
	if (status == NORMAL)
		exit(0);
	if (status == ABNORMAL)
	{
		ft_putendl_fd(s, 2);
		exit(1);
	}
	if (status == SYSERROR)
	{
		perror(s);
		exit(1);
	}
	return (0);
}
