#include "mlx.h"
#include <unistd.h>

#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*base_img;
	int		base_width;
	int		base_height;
	void	*move_img;
	int		move_width;
	int		move_height;
	int		wid_cnt;
	int		hei_cnt;
	int		move_x;
	int		move_y;
}				t_data;

int	close_win(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (keycode);
}

void	create_map(t_data *data)
{
	int		x_cnt = 0;
	int		y_cnt = 0;

	while (y_cnt < data->hei_cnt)
	{
		x_cnt = 0;
		while (x_cnt < data->wid_cnt)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->base_img, x_cnt * data->base_width, y_cnt * data->base_height);
			x_cnt++;
		}
		y_cnt++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->move_img, \
					data->move_x * data->base_width, data->move_y * data->base_height);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == LEFT && 0 < data->move_x)
		data->move_x--;
	if (keycode == RIGHT && data->move_x < data->wid_cnt - 1)
		data->move_x++;
	if (keycode == UP && 0 < data->move_y)
		data->move_y--;
	if (keycode == DOWN && data->move_y < data->hei_cnt - 1)
		data->move_y++;
	create_map(data);
	return (keycode);
}

int	main(void)
{
	t_data	data;
	char	*base_path = "./xpm/ship.xpm";
	char	*move_path = "./xpm/ship02.xpm";

	data.wid_cnt = 5;
	data.hei_cnt = 5;
	data.move_x = 0;
	data.move_y = 0;
	data.mlx = mlx_init();
	data.base_img = mlx_xpm_file_to_image(data.mlx, base_path, &data.base_width, &data.base_height);
	data.move_img = mlx_xpm_file_to_image(data.mlx, move_path, &data.move_width, &data.move_height);
	data.mlx_win = mlx_new_window(data.mlx, data.base_width * data.wid_cnt, data.base_height * data.hei_cnt, "Hello world!");
	create_map(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 33, 1 << 17, close, &data);
	mlx_loop(data.mlx);
}
