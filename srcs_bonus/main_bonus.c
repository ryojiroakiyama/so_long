#include "so_long_bonus.h"

void	free_2d_array(int **array, int until)
{
	if (array)
	{
		while (--until >= 0)
			free(array[until]);
		free(array);
	}
}

void	destroy_all_images(t_data *data)
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
			{
				if (data->img[square][side][action])
					mlx_destroy_image(data->mlx, \
						data->img[square][side][action]);
			}
		}
	}
}

int	ft_exit(int status, char *s, t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_all_images(data);
	if (data->putstr_img)
		mlx_destroy_image(data->mlx, data->putstr_img);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free_2d_array(data->map, data->square_num[X]);
	free(data->putstr);
	if (data->mlx)
		free(data->mlx);
	if (status == NORMAL)
		exit(0);
	if (status == ABNORMAL)
	{
		ft_putendl_fd(s, 2);
		exit(1);
	}
	if (status == SYSERROR)
	{
		perror(s);
		exit(1);
	}
	return (0);
}

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
	data->putstr = NULL;
	data->putstr_img = NULL;
	init_array_zero(data->putstr_img_len, COOR_NUM);
	data->enemy_moving = 0;
	data->map = NULL;
}

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
		data->putstr_img , 0, data->square_num[Y] * data->square_len[Y]);
	mlx_string_put(data->mlx, data->mlx_win, \
		5, data->square_num[Y] * data->square_len[Y] + 10, \
		0x00FF0000, data->putstr);
}

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

int	loop_func(t_data *data)
{
	move_enemy(data);
	run_animation(data);
	put_map(data);
	return (0);
}

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

int	is_error(int result, char *s, t_data *data)
{
	if (result < 0)
		ft_exit(SYSERROR, s, data);
	return (result);
}

int	read_map(char *map_path, t_data *data)
{
	int		fd;
	int		status;
	char	*line;
	int		error_cnt;

	fd = is_error(open(map_path, O_RDONLY), "open", data);
	status = 1;
	error_cnt = 0;
	while (status)
	{
		status = is_error(get_next_line(fd, &line), "gnl", data);
		if (status == 1)
		{
			data->square_num[Y]++;
			if (data->square_num[Y] == 1)
				data->square_num[X] = ft_strlen(line);
			else if ((int)ft_strlen(line) != data->square_num[X])
				error_cnt++;
		}
		if (status == 0 && line[0] != '\0')
			error_cnt++;
		free(line);
	}
	is_error(close(fd), "close", data);
	return (error_cnt || data->square_num[X] == 0 || data->square_num[Y] == 0);
}

int	**malloc_2d_array(int size1, int size2)
{
	int	cnt;
	int	**array;

	array = (int **)malloc(sizeof(int *) * size1);
	if (!array)
		return (NULL);
	cnt = -1;
	while (++cnt < size1)
	{
		array[cnt] = (int *)malloc(sizeof(int) * size2);
		if (!array)
		{
			free_2d_array(array, cnt);
			return (NULL);
		}
	}
	return (array);
}

int	is_square(char c)
{
	int		i;
	char	*squares;

	squares = "01CEP";
	i = 0;
	while (i < SQUARE_NUM)
	{
		if (squares[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	set_map(char *map_path, t_data *data)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	data->map = malloc_2d_array(data->square_num[X], data->square_num[Y]);
	if (!(data->map))
		ft_exit(SYSERROR, "malloc_2d_array", data);
	fd = is_error(open(map_path, O_RDONLY), "open", data);
	y = -1;
	while (++y < data->square_num[Y])
	{
		is_error(get_next_line(fd, &line), "gnl", data);
		x = -1;
		while (++x < data->square_num[X])
			data->map[x][y] = is_square(line[x]);
		free(line);
	}
	is_error(close(fd), "close", data);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->square_num[X])
	{
		y = -1;
		while (++y < data->square_num[Y])
		{
			data->type_cnt[data->map[x][y]]++;
			if (data->map[x][y] < 0)
				return (1);
			if ((x == 0 || x == data->square_num[X] - 1 \
				|| y == 0 || y == data->square_num[Y] - 1) \
				&& data->map[x][y] != WALL)
				return (1);
			if (data->map[x][y] == PLAYER)
			{
				data->posit[PLAYER][X] = x;
				data->posit[PLAYER][Y] = y;
			}
		}
	}
	return (data->type_cnt[COLL] == 0 || data->type_cnt[EXIT] == 0 \
			|| data->type_cnt[PLAYER] != 1);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac != 2)
		ft_exit(ABNORMAL, "Error\ninvalid number of argument", &data);
	if (read_map(av[1], &data))
		ft_exit(ABNORMAL, "Error\ninvalid map", &data);
	set_map(av[1], &data);
	if (check_map(&data))
		ft_exit(ABNORMAL, "Error\ninvalid map", &data);
	set_mlx_data(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, click_red_cross, &data);
	mlx_loop_hook(data.mlx, loop_func, &data);
	mlx_loop(data.mlx);
	return (0);
}
