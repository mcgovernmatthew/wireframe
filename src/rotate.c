#include "fdf.h"

void 			rotate_x(t_grid grid, float radians)
{
	int			x;
	int			y;
	t_rot		rot;
	t_point		center;

	y = 0;
	center = get_center(grid);
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			rot.y = grid.points[y][x].y - center.y;
			rot.z = grid.points[y][x].z - center.z;
			rot.d = hypot(rot.y, rot.z);
			rot.theta = atan2(rot.y, rot.z) + radians;
			grid.points[y][x].z = rot.d * cos(rot.theta) + center.z;
			grid.points[y][x].y = rot.d * sin(rot.theta) + center.y;
			x++;
		}
		y++;
	}
}

void 	rotate_y(t_grid grid, float radians)
{
	int		x;
	int		y;
	t_rot	rot;
	t_point	center;

	y = 0;
	center = get_center(grid);
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			rot.x = grid.points[y][x].x - center.x;
			rot.z = grid.points[y][x].z - center.z;
			rot.d = hypot(rot.x, rot.z);
			rot.theta = atan2(rot.x, rot.z) + radians;
			grid.points[y][x].z = rot.d * cos(rot.theta) + center.z;
			grid.points[y][x].x = rot.d * sin(rot.theta) + center.x;
			x++;
		}
		y++;
	}
}

void 	rotate_z(t_grid grid, float radians)
{
	int		x;
	int		y;
	t_rot	rot;
	t_point	center;

	y = 0;
	center = get_center(grid);
	while (y < grid.ylen)
	{
		x = 0;
		while (x < grid.xlen)
		{
			rot.x = grid.points[y][x].x - center.x;
			rot.y = grid.points[y][x].y - center.y;
			rot.d = hypot(rot.y, rot.x);
			rot.theta = atan2(rot.y, rot.x) + radians;
			grid.points[y][x].x = rot.d * cos(rot.theta) + center.x;
			grid.points[y][x].y = rot.d * sin(rot.theta) + center.y;
			x++;
		}
		y++;
	}
}
