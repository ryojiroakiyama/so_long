void	put_2d_array(t_data *data)
{
	int	x;
	int y;

	y = -1;
	while (++y < data->panel_num[Y])
	{
		x = -1;
		while (++x < data->panel_num[X])
			printf("%d", data->map[x][y]);
		printf("\n");
	}
}

void	make_2d_array(t_data *data)
{
	int	x;
	int	y;

	data->panel_num[X] = 10;
	data->panel_num[Y] = 10;
	data->map = (int **)malloc(sizeof(int *) * data->panel_num[X]);
	if (!data->map)
		exit(1);
	x = -1;
	while (++x < data->panel_num[X])
	{
		data->map[x] = (int *)malloc(sizeof(int) * data->panel_num[Y]);
		if (!data->map[x])
		{
			free_2d_array(data->map, x);
			exit (1);
		}
		y = -1;
		while (++y < data->panel_num[Y])
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
	data->panel_cnt[COLL] = 3;
}

