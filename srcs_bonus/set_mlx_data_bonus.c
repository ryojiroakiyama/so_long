#include "so_long_bonus.h"

void	set_enemy_posit(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->square_num[X])
	{
		y = -1;
		while (++y < data->square_num[Y])
		{
			if (data->map[x][y] == EMPTY)
			{
				data->posit[ENEMY][X] = x;
				data->posit[ENEMY][Y] = y;
				data->map[x][y] = ENEMY;
				data->type_cnt[ENEMY]++;
				return ;
			}
		}
	}
}

void	*is_null(void *result, char *s, t_data *data)
{
	if (!result)
		ft_exit(ABNORMAL, s, data);
	return (result);
}

void	set_putstr(t_data *data)
{
	char	*player_move;

	player_move = ft_itoa(data->move_cnt);
	if (!player_move)
		ft_exit(SYSERROR, "ft_itoa", data);
	free(data->putstr);
	data->putstr = NULL;
	data->putstr = ft_strjoin("move : ", player_move);
	free(player_move);
	if (!data->putstr)
		ft_exit(SYSERROR, "ft_strjoin", data);
}

void	set_mlx_data(t_data *data)
{
	set_enemy_posit(data);
	data->mlx = is_null(mlx_init(), "mlx_init", data);
	set_empty_img(data);
	set_wall_img(data);
	set_coll_img(data);
	set_exit_img(data);
	set_player_img(data);
	set_enemy_img(data);
	data->putstr_img = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/putstr/putstr.xpm", \
		&(data->putstr_img_len[X]), &(data->putstr_img_len[Y])), \
		"mlx_xpm_file_to_image", data);
	set_putstr(data);
	data->mlx_win = is_null(\
		mlx_new_window(data->mlx, \
		data->square_num[X] * data->square_len[X], \
		data->square_num[Y] * data->square_len[Y] + data->putstr_img_len[Y], \
		"so leng aaaaaai!"), \
		"mlx_new_window", data);
}
