#include <stdio.h>

enum e_point
{
	X,
	Y,
	POINT_NUM,
};

/*
int main(void)
{
	int x;
	int y;
	int mid;

	x = 100;
	mid = 150;
	while (x <= 200)
	{
		if (x <= mid)
			y = (mid - x) * (mid - x) / 5;
		else
			y = (x - mid) * (x - mid) / 5;
		printf("x = %d  y = %d\n", x, y);
x++;
	}
	return (0);
}
*/

int	main(void)
{
	int		points[7][POINT_NUM];
	int		center[POINT_NUM];
	int		to_point;
	int		i;

	center[X] = 250;
	center[Y] = 250;
	to_point = 100;
	points[0][X] = center[X] + to_point;
	points[0][Y] = center[Y];
	points[1][X] = center[X] + (to_point / 2);
	points[1][Y] = center[Y] - to_point;
	points[2][X] = center[X] - (to_point / 2);
	points[2][Y] = center[Y] - to_point;
	points[3][X] = center[X] - to_point;
	points[3][Y] = center[Y];
	points[4][X] = center[X] - (to_point / 2);
	points[4][Y] = center[Y] + to_point;
	points[5][X] = center[X] + (to_point / 2);
	points[5][Y] = center[Y] + to_point;
	points[6][X] = -1;
	points[6][Y] = -1;
	i = 0;
	while (1)
	{
		if (points[i + 1][X] == -1)
		{
			printf("(%d, %d) (%d, %d)\n", points[i][X], points[i][Y], points[0][X], points[0][Y]);
			break ;
		}
		printf("(%d, %d) (%d, %d)\n", points[i][X], points[i][Y], points[i + 1][X], points[i + 1][Y]);
		i++;
	}
	return (0);
}
