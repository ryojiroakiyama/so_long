#include "so_long.h"

void	init_array_zero(int *array, int size)
{
	int i;

	i = -1;
	while (++i < size)
		array[i] = 0;
}

void	init_img_data(t_data *data)
{
	int panel;
	int	side;
	int	action;

	panel = -1;
	while (++panel < PANEL_NUM)
	{
		side = -1;
		while (++side < SIDE_NUM)
		{
			action = -1;
			while (++action < ACTION_NUM)
				data->img[panel][side][action] = NULL;
		}
	}
}

void	set_enemy_posit(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->panel_num[X])
	{
		y = -1;
		while (++y < data->panel_num[Y])
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

void	set_empty_img(t_data *data)
{
	data->img[EMPTY][FRONT_SIDE][ACTION1] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/empty/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EMPTY][FRONT_SIDE][ACTION2] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/empty/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EMPTY][FRONT_SIDE][ACTION3] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/empty/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EMPTY][FRONT_SIDE][ACTION4] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/empty/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img_side[EMPTY] = FRONT_SIDE;
	data->img_action[EMPTY] = ACTION1;
}

void	set_wall_img(t_data *data)
{
	data->img[WALL][FRONT_SIDE][ACTION1] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/wall/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[WALL][FRONT_SIDE][ACTION2] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/wall/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[WALL][FRONT_SIDE][ACTION3] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/wall/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[WALL][FRONT_SIDE][ACTION4] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/wall/front/front.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img_side[WALL] = FRONT_SIDE;
	data->img_action[WALL] = ACTION1;
}

void	set_coll_img(t_data *data)
{
	data->img[COLL][FRONT_SIDE][ACTION1] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/coll/front/front1.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[COLL][FRONT_SIDE][ACTION2] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/coll/front/front24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[COLL][FRONT_SIDE][ACTION3] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/coll/front/front3.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[COLL][FRONT_SIDE][ACTION4] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/coll/front/front24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img_side[COLL] = FRONT_SIDE;
	data->img_action[COLL] = ACTION1;
}

void	set_exit_img(t_data *data)
{
	data->img[EXIT][FRONT_SIDE][ACTION1] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/exit/front/front13.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EXIT][FRONT_SIDE][ACTION2] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/exit/front/front24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EXIT][FRONT_SIDE][ACTION3] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/exit/front/front13.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EXIT][FRONT_SIDE][ACTION4] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/exit/front/front24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img_side[EXIT] = FRONT_SIDE;
	data->img_action[EXIT] = ACTION1;
}

void	set_player_img(t_data *data)
{
	data->img[PLAYER][FRONT_SIDE][ACTION1] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/player/front/front1.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[PLAYER][FRONT_SIDE][ACTION2] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/player/front/front24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[PLAYER][FRONT_SIDE][ACTION3] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/player/front/front3.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[PLAYER][FRONT_SIDE][ACTION4] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/player/front/front24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img_side[PLAYER] = FRONT_SIDE;
	data->img_action[PLAYER] = ACTION1;
}

void	set_enemy_img(t_data *data)
{
	data->img[ENEMY][RIGHT_SIDE][ACTION1] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/enemy/right/right1.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[ENEMY][RIGHT_SIDE][ACTION2] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/enemy/right/right24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[ENEMY][RIGHT_SIDE][ACTION3] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/enemy/right/right3.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[ENEMY][RIGHT_SIDE][ACTION4] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/enemy/right/right24.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img_side[ENEMY] = RIGHT_SIDE;
	data->img_action[ENEMY] = ACTION1;
}

void	init_mlx_data(t_data *data)
{
	data->mlx = mlx_init();
	init_img_data(data);
	set_empty_img(data);
	set_wall_img(data);
	set_coll_img(data);
	set_exit_img(data);
	set_player_img(data);
	set_enemy_img(data);
	data->mlx_win = mlx_new_window(data->mlx, \
		data->panel_num[X] * data->img_length[X], data->panel_num[Y] * data->img_length[Y], "Hello world!");
	data->move_cnt = 0;
	set_enemy_posit(data);
	data->enemy_moving = 0;
}

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
	int panel;
	int	side;
	int	action;

	panel = -1;
	while (++panel < PANEL_NUM)
	{
		side = -1;
		while (++side < SIDE_NUM)
		{
			action = -1;
			while (++action < ACTION_NUM)
			{
				if (data->img[panel][side][action] != NULL)
					mlx_destroy_image(data->mlx, data->img[panel][side][action]);
			}
		}
	}
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_all_images(data);
	mlx_destroy_display(data->mlx);
	free_2d_array(data->map, data->panel_num[X]);
	free(data->mlx);
	exit(0);
	return (0);
}

void	print_info(t_data *data)
{
	ft_putstr_fd("\033[2J", 1);
	ft_putstr_fd("number of moves : ", 1);
	ft_putnbr_fd(data->move_cnt, 1);
	ft_putstr_fd("\ncollectible remaining : ", 1);
	ft_putnbr_fd(data->panel_cnt[COLL], 1);
	ft_putstr_fd("\n", 1);
}

void	put_map(t_data *data)
{
	int	x;
	int	y;
	int	panel;

	x = -1;
	while (++x < data->panel_num[X])
	{
		y = -1;
		while (++y < data->panel_num[Y])
		{
			panel = data->map[x][y];
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->img[panel][data->img_side[panel]][data->img_action[panel]], \
			x * data->img_length[X], y * data->img_length[Y]);
		}
	}
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

void	serch_empty(t_data *data)
{
	int next[2];

	if (get_next_posit(data->posit[ENEMY], next, data->enemy_moving, data) == EMPTY)
		move_to_empty(ENEMY, next, data->enemy_moving, data);
	else if (get_next_posit(data->posit[ENEMY], next, UP, data) == EMPTY)
		move_to_empty(ENEMY, next, UP, data);
	else if (get_next_posit(data->posit[ENEMY], next, RIGHT, data) == EMPTY)
		move_to_empty(ENEMY, next, RIGHT, data);
	else if (get_next_posit(data->posit[ENEMY], next, DOWN, data) == EMPTY)
		move_to_empty(ENEMY, next, DOWN, data);
	else if (get_next_posit(data->posit[ENEMY], next, LEFT, data) == EMPTY)
		move_to_empty(ENEMY, next, LEFT, data);
}

void	move_enemy(t_data *data)
{
	static int	cnt;
	int			direction;
	int			panel;
	int			next[2];

	cnt++;
	if (cnt == 2000)
	{
		direction = which_direction(data->posit[ENEMY], data->posit[PLAYER]);
		panel = get_next_posit(data->posit[ENEMY], next, direction, data);
		if (panel == PLAYER)
			close_win(data);
		else if (panel == EMPTY)
			move_to_empty(ENEMY, next, direction, data);
		else
			serch_empty(data);
		cnt = 0;
	}
}

void	run_animation(t_data *data)
{
	static int	cnt;
	int			panel;

	cnt++;
	if (cnt == 500)
	{
		panel = -1;
		while (++panel < PANEL_NUM)
		{
			data->img_action[panel]++;
			if (data->img_action[panel] == ACTION_NUM)
				data->img_action[panel] = 0;
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

int	key_hook(int keycode, t_data *data)
{
	int	next_panel;
	int	next[2];

	next_panel = get_next_posit(data->posit[PLAYER], next, keycode, data);
	if (next_panel == EXIT && data->panel_cnt[COLL] == 0)
		close_win(data);
	if (next_panel == ENEMY)
		close_win(data);
	if (next_panel == COLL)
	{
		data->map[next[X]][next[Y]] = EMPTY;
		data->panel_cnt[COLL]--;
		move_to_empty(PLAYER, next, keycode, data);
	}
	if (next_panel == EMPTY)
		move_to_empty(PLAYER, next, keycode, data);
	if (keycode == ESC)
		close_win(data);
	print_info(data);
	return (keycode);
}

int	exit_or_not(int result)
{
	if (result < 0)
		exit(1);
	return (result);
}

int	read_map(char *map_path, t_data *data)
{
	int		fd;
	int		status;
	char	*line;
	int		error_cnt;

	fd = exit_or_not(open(map_path, O_RDONLY));
	status = 1;
	error_cnt = 0;
	while (status)
	{
		status = exit_or_not(get_next_line(fd, &line));
		if (status == 1)
		{
			data->panel_num[Y]++;
			if (data->panel_num[Y] == 1)
				data->panel_num[X] = ft_strlen(line);
			else if ((int)ft_strlen(line) != data->panel_num[X])
				error_cnt++;
		}
		if (status == 0 && line[0] != '\0')
			error_cnt++;
		free(line);
	}
	exit_or_not(close(fd));
	return (error_cnt || data->panel_num[X] == 0 || data->panel_num[Y] == 0);
}

int	**malloc_2d_array(int size1, int size2)
{
	int cnt;
	int **array;

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

int	is_panel(char c)
{
	int		i;
	char	*panels;

	panels = "01CEP";
	i = 0;
	while (i < PANEL_NUM)
	{
		if (panels[i] == c)
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

	data->map = malloc_2d_array(data->panel_num[X], data->panel_num[Y]);
	if (!(data->map))
		exit(1);
	fd = exit_or_not(open(map_path, O_RDONLY));
	y = -1;
	while (++y < data->panel_num[Y])
	{
		exit_or_not(get_next_line(fd, &line));
		x = -1;
		while (++x < data->panel_num[X])
			data->map[x][y] = is_panel(line[x]);
		free(line);
	}
	exit_or_not(close(fd));
}

int		check_map(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->panel_num[X])
	{
		y = -1;
		while (++y < data->panel_num[Y])
		{
			if ((x == 0 || x == data->panel_num[X] - 1 || y == 0 || y == data->panel_num[Y] - 1) && data->map[x][y] != WALL)
				return (1);
			if (data->map[x][y] == COLL)
				data->panel_cnt[COLL]++;
			if (data->map[x][y] == EXIT)
				data->panel_cnt[EXIT]++;
			if (data->map[x][y] == PLAYER)
			{
				data->posit[PLAYER][X] = x;
				data->posit[PLAYER][Y] = y;
				data->panel_cnt[PLAYER]++;
			}
		}
	}
	return (data->panel_cnt[COLL] == 0 || data->panel_cnt[EXIT] == 0 || data->panel_cnt[PLAYER] != 1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(1);
	init_array_zero(data.panel_num, COOR_NUM);
	init_array_zero(data.panel_cnt, PANEL_NUM);
	if (read_map(av[1], &data))
		exit(1);
	set_map(av[1], &data);
	if (check_map(&data))
	{
		free_2d_array(data.map, data.panel_num[X]);
		exit(1);
	}
	init_mlx_data(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_win, &data);
	mlx_loop_hook(data.mlx, loop_func, &data);
	print_info(&data);
	mlx_loop(data.mlx);
	return (0);
}
