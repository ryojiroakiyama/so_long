#include "so_long_bonus.h"

void	set_empty_img(t_data *data)
{
	data->img[EMPTY][FRONT_SIDE][ACTION1] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/empty/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[EMPTY][FRONT_SIDE][ACTION2] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/empty/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[EMPTY][FRONT_SIDE][ACTION3] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/empty/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[EMPTY][FRONT_SIDE][ACTION4] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/empty/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->square_side[EMPTY] = FRONT_SIDE;
	data->square_act[EMPTY] = ACTION1;
}

void	set_wall_img(t_data *data)
{
	data->img[WALL][FRONT_SIDE][ACTION1] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/wall/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[WALL][FRONT_SIDE][ACTION2] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/wall/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[WALL][FRONT_SIDE][ACTION3] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/wall/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[WALL][FRONT_SIDE][ACTION4] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/wall/front/front.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->square_side[WALL] = FRONT_SIDE;
	data->square_act[WALL] = ACTION1;
}

void	set_coll_img(t_data *data)
{
	data->img[COLL][FRONT_SIDE][ACTION1] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/coll/front/front1.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[COLL][FRONT_SIDE][ACTION2] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/coll/front/front24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[COLL][FRONT_SIDE][ACTION3] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/coll/front/front3.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->img[COLL][FRONT_SIDE][ACTION4] = is_null(\
		mlx_xpm_file_to_image(data->mlx, "./xpm/coll/front/front24.xpm", \
		&(data->square_len[X]), &(data->square_len[Y])), \
		"mlx_xpm_file_to_image", data);
	data->square_side[COLL] = FRONT_SIDE;
	data->square_act[COLL] = ACTION1;
}
