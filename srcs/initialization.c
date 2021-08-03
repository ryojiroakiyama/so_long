#include "so_long.h"

void	init_array_zero(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		array[i] = 0;
}

void	init_img(t_data *data)
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
				data->img[square][side][action] = NULL;
		}
	}
}

void	init_data(t_data *data)
{
	int	square;

	data->mlx = NULL;
	data->mlx_win = NULL;
	init_img(data);
	init_array_zero(data->square_side, SQUARE_NUM);
	init_array_zero(data->square_act, SQUARE_NUM);
	init_array_zero(data->square_len, COOR_NUM);
	init_array_zero(data->square_num, COOR_NUM);
	init_array_zero(data->type_cnt, SQUARE_NUM);
	square = -1;
	while (++square < SQUARE_NUM)
		init_array_zero(data->posit[square], COOR_NUM);
	data->move_cnt = 0;
	data->map = NULL;
}

