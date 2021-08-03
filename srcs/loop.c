#include "so_long.h"

void	put_map(t_data *data)
{
	int	x;
	int	y;
	int	square;

	x = -1;
	while (++x < data->square_num[X])
	{
		y = -1;
		while (++y < data->square_num[Y])
		{
			square = data->map[x][y];
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->img[square] \
			[data->square_side[square]] \
			[data->square_act[square]], \
			x * data->square_len[X], y * data->square_len[Y]);
		}
	}
}

void	run_animation(t_data *data)
{
	static int	cnt;
	int			square;

	cnt++;
	if (cnt == 500)
	{
		square = -1;
		while (++square < SQUARE_NUM)
		{
			data->square_act[square]++;
			if (data->square_act[square] == ACTION_NUM)
				data->square_act[square] = 0;
		}
		cnt = 0;
	}
}

int	loop_func(t_data *data)
{
	run_animation(data);
	put_map(data);
	return (0);
}
