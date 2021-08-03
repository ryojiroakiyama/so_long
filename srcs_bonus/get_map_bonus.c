#include "so_long_bonus.h"

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
