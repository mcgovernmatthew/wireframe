#include "fdf.h"

void 	scale_z(t_grid grid, float scale)
{
	int x;
	int y;

	y = 0;
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			grid.points[y][x].z *= scale;
			x++;
		}
		y++;
	}
}

void			scale_xy(t_grid grid, float scale)
{
	int			x;
	int			y;

	y = 0;
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			grid.points[y][x].x *= scale;
			grid.points[y][x].y *= scale;
			x++;
		}
		y++;
	}
}
