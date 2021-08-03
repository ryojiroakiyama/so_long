#include "so_long.h"

void	print_info(t_data *data)
{
	ft_putstr_fd("\033[2J", 1);
	ft_putstr_fd("number of moves : ", 1);
	ft_putnbr_fd(data->move_cnt, 1);
	ft_putstr_fd("\ncollectible remaining : ", 1);
	ft_putnbr_fd(data->type_cnt[COLL], 1);
	ft_putstr_fd("\n", 1);
}

int	get_next_posit(int *now, int *next, int direction, t_data *data)
{
	if (direction == LEFT)
	{
		next[X] = now[X] - 1;
		next[Y] = now[Y];
		return (data->map[next[X]][next[Y]]);
	}
	if (direction == RIGHT)
	{
		next[X] = now[X] + 1;
		next[Y] = now[Y];
		return (data->map[next[X]][next[Y]]);
	}
	if (direction == UP)
	{
		next[X] = now[X];
		next[Y] = now[Y] - 1;
		return (data->map[next[X]][next[Y]]);
	}
	if (direction == DOWN)
	{
		next[X] = now[X];
		next[Y] = now[Y] + 1;
		return (data->map[next[X]][next[Y]]);
	}
	return (-1);
}

void	move_to_empty(int who, int *next, t_data *data)
{
	if (who == PLAYER)
	{
		data->map[data->posit[PLAYER][X]][data->posit[PLAYER][Y]] = EMPTY;
		data->map[next[X]][next[Y]] = PLAYER;
		data->posit[PLAYER][X] = next[X];
		data->posit[PLAYER][Y] = next[Y];
		data->move_cnt++;
	}
}

int	key_hook(int keycode, t_data *data)
{
	int	next_square;
	int	next[2];

	next_square = get_next_posit(data->posit[PLAYER], next, keycode, data);
	if (next_square == EXIT && data->type_cnt[COLL] == 0)
		ft_exit(NORMAL, NULL, data);
	if (next_square == COLL)
	{
		data->map[next[X]][next[Y]] = EMPTY;
		data->type_cnt[COLL]--;
		move_to_empty(PLAYER, next, data);
	}
	if (next_square == EMPTY)
		move_to_empty(PLAYER, next, data);
	if (keycode == ESC)
		ft_exit(NORMAL, NULL, data);
	print_info(data);
	return (keycode);
}

int	click_red_cross(t_data *data)
{
	ft_exit(NORMAL, NULL, data);
	return (0);
}
