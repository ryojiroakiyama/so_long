#include "so_long_bonus.h"

void	move_enemy(t_data *data)
{
	static int	cnt;
	int			direction;
	int			square;
	int			next[2];

	cnt++;
	if (cnt == 2000)
	{
		direction = which_direction(data->posit[ENEMY], data->posit[PLAYER]);
		square = get_next_posit(data->posit[ENEMY], next, direction, data);
		if (square == PLAYER)
			ft_exit(NORMAL, NULL, data);
		else if (square == EMPTY)
			move_to_empty(ENEMY, next, direction, data);
		else if (get_next_posit(data->posit[ENEMY], next, \
			data->enemy_moving, data) == EMPTY)
			move_to_empty(ENEMY, next, data->enemy_moving, data);
		else
		{
			direction = get_next_direction(next, EMPTY, data);
			if (0 < direction)
				move_to_empty(ENEMY, next, direction, data);
		}
		cnt = 0;
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
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->putstr_img, 0, data->square_num[Y] * data->square_len[Y]);
	mlx_string_put(data->mlx, data->mlx_win, \
		5, data->square_num[Y] * data->square_len[Y] + 10, \
		0x00FF0000, data->putstr);
}

int	loop_func(t_data *data)
{
	move_enemy(data);
	run_animation(data);
	put_map(data);
	return (0);
}
