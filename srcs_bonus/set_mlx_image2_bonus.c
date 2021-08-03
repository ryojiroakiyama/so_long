#include "so_long_bonus.h"

void	set_exit_img(t_data *data)
{
	data->img[EXIT][FRONT_SIDE][ACTION1] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/exit/front/front13.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[EXIT][FRONT_SIDE][ACTION2] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/exit/front/front24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[EXIT][FRONT_SIDE][ACTION3] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/exit/front/front13.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[EXIT][FRONT_SIDE][ACTION4] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/exit/front/front24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->square_side[EXIT] = FRONT_SIDE;
	data->square_act[EXIT] = ACTION1;
}

void	set_player_img(t_data *data)
{
	data->img[PLAYER][FRONT_SIDE][ACTION1] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/player/front/front1.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[PLAYER][FRONT_SIDE][ACTION2] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/player/front/front24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[PLAYER][FRONT_SIDE][ACTION3] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/player/front/front3.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[PLAYER][FRONT_SIDE][ACTION4] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/player/front/front24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->square_side[PLAYER] = FRONT_SIDE;
	data->square_act[PLAYER] = ACTION1;
}

void	set_enemy_img(t_data *data)
{
	data->img[ENEMY][RIGHT_SIDE][ACTION1] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/enemy/right/right1.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[ENEMY][RIGHT_SIDE][ACTION2] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/enemy/right/right24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[ENEMY][RIGHT_SIDE][ACTION3] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/enemy/right/right3.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[ENEMY][RIGHT_SIDE][ACTION4] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/enemy/right/right24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->square_side[ENEMY] = RIGHT_SIDE;
	data->square_act[ENEMY] = ACTION1;
}
