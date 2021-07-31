#include "so_long.h"

void	init_array_zero(int *array, int size)
{
	int i;

	i = -1;
	while (++i < size)
		array[i] = 0;
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
				data->e_posit[X] = x;
				data->e_posit[Y] = y;
				data->map[x][y] = ENEMY;
				return ;
			}
		}
	}
}

void	init_mlx_data(t_data *data)
{
	data->mlx = mlx_init();
	data->img[EMPTY] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/forest.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[WALL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/wall.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[COLL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/coll1_empty.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EXIT] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/exit1_empty.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[PLAYER] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/player.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[ENEMY] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/enemy1_empty.xpm", &(data->img_length[X]), &(data->img_length[Y]));
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
	int i;

	i = -1;
	while (++i < PANEL_NUM)
		mlx_destroy_image(data->mlx, data->img[i]);
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

	x = -1;
	while (++x < data->panel_num[X])
	{
		y = -1;
		while (++y < data->panel_num[Y])
		{
			mlx_put_image_to_window\
			(data->mlx, data->mlx_win, data->img[data->map[x][y]], \
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
		data->map[data->e_posit[X]][data->e_posit[Y]] = EMPTY;
		data->map[next[X]][next[Y]] = ENEMY;
		data->e_posit[X] = next[X];
		data->e_posit[Y] = next[Y];
		data->enemy_moving = direction;
	}
}

void	enemy_move_empty(t_data *data)
{
	int next[2];

	if (get_next_posit(data->e_posit, next, data->enemy_moving, data) == EMPTY)
		move_to_empty(ENEMY, next, ENEMY, data);
	else if (get_next_posit(data->e_posit, next, UP, data) == EMPTY)
		move_to_empty(ENEMY, next, UP, data);
	else if (get_next_posit(data->e_posit, next, RIGHT, data) == EMPTY)
		move_to_empty(ENEMY, next, RIGHT, data);
	else if (get_next_posit(data->e_posit, next, DOWN, data) == EMPTY)
		move_to_empty(ENEMY, next, DOWN, data);
	else if (get_next_posit(data->e_posit, next, LEFT, data) == EMPTY)
		move_to_empty(ENEMY, next, LEFT, data);
}

void	enemy_move_next(int next_x, int next_y, t_data *data, int direction)
{
	if (data->map[next_x][next_y] == PLAYER)
		close_win(data);
	if (data->map[next_x][next_y] == EMPTY)
	{
		data->map[data->e_posit[X]][data->e_posit[Y]] = EMPTY;
		data->map[next_x][next_y] = ENEMY;
		data->e_posit[X] = next_x;
		data->e_posit[Y] = next_y;
		data->enemy_moving = direction;
		return ;
	}
	enemy_move_empty(data);
}

void	move_enemy(t_data *data)
{
	static int	cnt;
	int			to_player;

	cnt++;
	if (cnt == 2000)
	{
		to_player = which_direction(data->e_posit, data->p_posit);
		if (to_player == LEFT)
			enemy_move_next(data->e_posit[X] - 1, data->e_posit[Y], data, LEFT);
		else if (to_player == RIGHT)
			enemy_move_next(data->e_posit[X] + 1, data->e_posit[Y], data, RIGHT);
		else if (to_player == UP)
			enemy_move_next(data->e_posit[X], data->e_posit[Y] - 1, data, UP);
		else if (to_player == DOWN)
			enemy_move_next(data->e_posit[X], data->e_posit[Y] + 1, data, DOWN);
		else
			enemy_move_empty(data);
		cnt = 0;
	}
}

int	loop_func(t_data *data)
{
	move_enemy(data);
	put_map(data);
	return (0);
}

void	player_move_next(int next_x, int next_y, t_data *data)
{
	if (data->map[next_x][next_y] == WALL)
		return ;
	if (data->map[next_x][next_y] == EXIT)
	{
		if (data->panel_cnt[COLL] == 0)
			close_win(data);
		else
			return ;
	}
	if (data->map[next_x][next_y] == ENEMY)
		close_win(data);
	if (data->map[next_x][next_y] == COLL)
		data->panel_cnt[COLL]--;
	data->map[data->p_posit[X]][data->p_posit[Y]] = EMPTY;
	data->map[next_x][next_y] = PLAYER;
	data->p_posit[X] = next_x;
	data->p_posit[Y] = next_y;
	data->move_cnt++;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == LEFT)
		player_move_next(data->p_posit[X] - 1, data->p_posit[Y], data);
	if (keycode == RIGHT)
		player_move_next(data->p_posit[X] + 1, data->p_posit[Y], data);
	if (keycode == UP)
		player_move_next(data->p_posit[X], data->p_posit[Y] - 1, data);
	if (keycode == DOWN)
		player_move_next(data->p_posit[X], data->p_posit[Y] + 1, data);
	if (keycode == ESC)
		close_win(data);
//	put_map(data);
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
				data->p_posit[X] = x;
				data->p_posit[Y] = y;
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
