#include "fdf.h"

float			mean_x(t_grid grid)
{
	int			x;
	int			y;
	int			i;
	float		sum;

	i = 0;
	y = 0;
	sum = 0;
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			sum += grid.points[y][x++].x;
			i++;
		}
		y++;
	}
	return (sum / (float)i);
}

float			mean_y(t_grid grid)
{
	int			x;
	int			y;
	int			i;
	float		sum;

	i = 0;
	y = 0;
	sum = 0;
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			sum += grid.points[y][x++].y;
			i++;
		}
		y++;
	}
	return (sum / (float)i);
}

float			mean_z(t_grid grid)
{
	int			x;
	int			y;
	int			i;
	float		sum;

	i = 0;
	y = 0;
	sum = 0;
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			sum += grid.points[y][x++].z;
			i++;
		}
		y++;
	}
	return (sum / (float)i);
}
