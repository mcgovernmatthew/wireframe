#include "fdf.h"

t_point			get_center(t_grid grid)
{
	return (set_point(mean_x(grid), mean_y(grid), mean_z(grid)));
}

t_point			set_point(float x, float y, float z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

int		get_xoff(t_env *env)
{
	t_point center;

	center = get_center(env->grid);
	return (env->halfwide - center.x);
}

int		get_yoff(t_env *env)
{
	t_point center;

	center = get_center(env->grid);
	return (env->halfhigh - center.y);
}
