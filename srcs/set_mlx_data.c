#include "so_long.h"

void	*is_null(void *result, char *s, t_data *data)
{
	if (!result)
		ft_exit(ABNORMAL, s, data);
	return (result);
}

void	set_mlx_data(t_data *data)
{
	data->mlx = is_null(mlx_init(), "mlx_init", data);
	set_empty_img(data);
	set_wall_img(data);
	set_coll_img(data);
	set_exit_img(data);
	set_player_img(data);
	data->mlx_win = is_null(\
		mlx_new_window(data->mlx, \
		data->square_num[X] * data->square_len[X], \
		data->square_num[Y] * data->square_len[Y], \
		"so leng aaaaaai!"), \
		"mlx_new_window", data);
}
