#include "so_long_bonus.h"

int	click_red_cross(t_data *data)
{
	ft_exit(NORMAL, NULL, data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	int	next_square;
	int	next[2];

	next_square = get_next_posit(data->posit[PLAYER], next, keycode, data);
	if (next_square == EXIT && data->type_cnt[COLL] == 0)
		ft_exit(NORMAL, NULL, data);
	if (next_square == ENEMY)
		ft_exit(NORMAL, NULL, data);
	if (next_square == COLL)
	{
		data->map[next[X]][next[Y]] = EMPTY;
		data->type_cnt[COLL]--;
		move_to_empty(PLAYER, next, keycode, data);
	}
	if (next_square == EMPTY)
		move_to_empty(PLAYER, next, keycode, data);
	if (keycode == ESC)
		ft_exit(NORMAL, NULL, data);
	set_putstr(data);
	return (keycode);
}
