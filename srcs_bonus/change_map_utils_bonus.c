#include "so_long_bonus.h"

int	which_direction(int *src, int *dst)
{
	if (src[X] == dst[X])
	{
		if (src[Y] < dst[Y])
			return (DOWN);
		return (UP);
	}
	else if (src[Y] == dst[Y])
	{
		if (src[X] < dst[X])
			return (RIGHT);
		return (LEFT);
	}
	else
		return (-1);
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

void	move_to_empty(int who, int *next, int direction, t_data *data)
{
	if (who == ENEMY)
	{
		data->map[data->posit[ENEMY][X]][data->posit[ENEMY][Y]] = EMPTY;
		data->map[next[X]][next[Y]] = ENEMY;
		data->posit[ENEMY][X] = next[X];
		data->posit[ENEMY][Y] = next[Y];
		data->enemy_moving = direction;
	}
	if (who == PLAYER)
	{
		data->map[data->posit[PLAYER][X]][data->posit[PLAYER][Y]] = EMPTY;
		data->map[next[X]][next[Y]] = PLAYER;
		data->posit[PLAYER][X] = next[X];
		data->posit[PLAYER][Y] = next[Y];
		data->move_cnt++;
	}
}

int	get_next_direction(int *next, int square, t_data *data)
{
	if (get_next_posit(data->posit[ENEMY], next, UP, data) == square)
		return (UP);
	else if (get_next_posit(data->posit[ENEMY], next, RIGHT, data) == square)
		return (RIGHT);
	else if (get_next_posit(data->posit[ENEMY], next, DOWN, data) == square)
		return (DOWN);
	else if (get_next_posit(data->posit[ENEMY], next, LEFT, data) == square)
		return (LEFT);
	else
		return (-1);
}
