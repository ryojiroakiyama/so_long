#include "so_long.h"

void	init_map_data(t_data *data)
{
	data->panel_cnt[X] = 0;
	data->panel_cnt[Y] = 0;
	data->p_posit[X] = 0;
	data->p_posit[Y] = 0;
	data->coll_cnt[NOW] = 0;
	data->coll_cnt[MAX] = 0;
	data->map = NULL;
}

void	init_mlx_data(t_data *data)
{
	data->mlx = mlx_init();
	data->img[EMPTY] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/forest.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[WALL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/tree.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[COLL] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/old-man.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[EXIT] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/escape.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->img[PLAYER] = mlx_xpm_file_to_image\
		(data->mlx, "./xpm/monster.xpm", &(data->img_length[X]), &(data->img_length[Y]));
	data->mlx_win = mlx_new_window(data->mlx, \
		data->panel_cnt[X] * data->img_length[X], data->panel_cnt[Y] * data->img_length[Y], "Hello world!");
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

void	put_2d_array(t_data *data)
{
	int	x;
	int y;

	x = -1;
	while (++x < data->panel_cnt[X])
	{
		y = -1;
		while (++y < data->panel_cnt[Y])
			printf("(%d, %d)->%d\n", x, y, data->map[x][y]);
	}
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_all_images(data);
	mlx_destroy_display(data->mlx);
	free_2d_array(data->map, data->panel_cnt[X]);
	free(data->mlx);
	exit(0);
	return (0);
}

void	create_map(t_data *data)
{
	int	x;
	int	y;

//	mlx_clear_window(data->mlx, data->mlx_win);
	x = -1;
	while (++x < data->panel_cnt[X])
	{
		y = -1;
		while (++y < data->panel_cnt[Y])
		{
			mlx_put_image_to_window\
			(data->mlx, data->mlx_win, data->img[data->map[x][y]], \
			x * data->img_length[X], y * data->img_length[Y]);
		}
	}
}

void	move_next_or_not(int next_x, int next_y, t_data *data)
{
	if (next_x < 0 || data->panel_cnt[X] - 1 < next_x || next_y < 0 || data->panel_cnt[Y] - 1 < next_y)
		return ;
	if (data->map[next_x][next_y] == WALL)
		return ;
	if (data->map[next_x][next_y] == EXIT)
	{
		if (data->coll_cnt[NOW] == data->coll_cnt[MAX])
			close_win(data);
		else
			return ;
	}
	if (data->map[next_x][next_y] == COLL)
		data->coll_cnt[NOW]++;
	data->map[data->p_posit[X]][data->p_posit[Y]] = EMPTY;
	data->map[next_x][next_y] = PLAYER;
	data->p_posit[X] = next_x;
	data->p_posit[Y] = next_y;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == LEFT)
		move_next_or_not(data->p_posit[X] - 1, data->p_posit[Y], data);
	if (keycode == RIGHT)
		move_next_or_not(data->p_posit[X] + 1, data->p_posit[Y], data);
	if (keycode == UP)
		move_next_or_not(data->p_posit[X], data->p_posit[Y] - 1, data);
	if (keycode == DOWN)
		move_next_or_not(data->p_posit[X], data->p_posit[Y] + 1, data);
	if (keycode == ESC)
		close_win(data);
	create_map(data);
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
			data->panel_cnt[Y]++;
			if (data->panel_cnt[Y] == 1)
				data->panel_cnt[X] = ft_strlen(line);
			else if ((int)ft_strlen(line) != data->panel_cnt[X])
				error_cnt++;
		}
		if (status == 0 && line[0] != '\0')
			error_cnt++;
		free(line);
	}
	exit_or_not(close(fd));
	return (error_cnt);
}

int	**create_2d_array(int size1, int size2)
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

	data->map = create_2d_array(data->panel_cnt[X], data->panel_cnt[Y]);
	if (!(data->map))
		exit(1);
	fd = exit_or_not(open(map_path, O_RDONLY));
	y = -1;
	while (++y < data->panel_cnt[Y])
	{
		exit_or_not(get_next_line(fd, &line));
		x = -1;
		while (++x < data->panel_cnt[X])
			data->map[x][y] = is_panel(line[x]);
		free(line);
	}
}

void	make_2d_array(t_data *data)
{
	int	x;
	int	y;

	data->panel_cnt[X] = 10;
	data->panel_cnt[Y] = 10;
	data->map = (int **)malloc(sizeof(int *) * data->panel_cnt[X]);
	if (!data->map)
		exit(1);
	x = -1;
	while (++x < data->panel_cnt[X])
	{
		data->map[x] = (int *)malloc(sizeof(int) * data->panel_cnt[Y]);
		if (!data->map[x])
		{
			free_2d_array(data->map, x);
			exit (1);
		}
		y = -1;
		while (++y < data->panel_cnt[Y])
			data->map[x][y] = EMPTY;
	}
	data->p_posit[X] = 0;
	data->p_posit[Y] = 0;
	data->map[data->p_posit[X]][data->p_posit[Y]] = PLAYER;
	data->map[3][3] = COLL;
	data->map[5][5] = COLL;
	data->map[8][8] = COLL;
	data->map[7][7] = WALL;
	data->map[9][7] = WALL;
	data->map[4][7] = EXIT;
	data->coll_cnt[MAX] = 3;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(1);
	init_map_data(&data);
	if (read_map(av[1], &data) || !(data.panel_cnt[X]) || !(data.panel_cnt[Y]))
		exit(1);
	set_map(av[1], &data);
	put_2d_array(&data);
	free_2d_array(data.map, data.panel_cnt[X]);
/*	make_2d_array(&data);
	init_mlx_data(&data);
	create_map(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 33, 1L << 17, close_win, &data);
	mlx_loop(data.mlx);
*/	return (0);
}
