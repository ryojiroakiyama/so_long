#include "so_long.h"

int	is_error(int result, char *s, t_data *data)
{
	if (result < 0)
		ft_exit(SYSERROR, s, data);
	return (result);
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
