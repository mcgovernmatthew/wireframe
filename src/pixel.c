#include "fdf.h"

void			pixel_to_image(t_env *env, int x, int y, int color)
{
	int			i;

	if (x >= env->width)
		return ;
	if (y >= env->height)
		return ;
	i = (x * 4) + (y * env->size_line);

	if (x > 0 && y > 0)
	{
		env->data[i++] = color & 0xFF;
		env->data[i++] = (color >> 8) & 0xFF;
		env->data[i] = (color >> 16) & 0xFF;
	}
}