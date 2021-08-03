#include "so_long_bonus.h"

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
