#include "fdf.h"
#include <stdio.h>
#include "libft.h"
#include <mlx.h>
#include <math.h>

t_line			make_line(t_point start, t_point end, int xoff, int yoff)
{
	t_line		line;

	line.x0 = start.x + xoff;
	line.y0 = start.y + yoff;
	line.x1 = end.x + xoff;
	line.y1 = end.y + yoff;
	return (line);
}

void			line_draw(t_line line, t_env *env)
{
	line.steep = (abs(line.y1 - line.y0) > abs(line.x1 - line.x0)) ? 1 : 0;
	if (line.steep)
		ft_swaplol(&line.x0, &line.y0, &line.x1, &line.y1);
	if (line.x0 > line.x1)
		ft_swaplol(&line.x0, &line.x1, &line.y0, &line.y1);
	line.deltax = line.x1 - line.x0;
	line.deltay = abs(line.y1 - line.y0);
	line.error = 0;
	line.deltaerr = line.deltay / line.deltax;
	line.y = line.y0;
	(line.y0 < line.y1) ? (line.ystep = 1) : (line.ystep = -1);
	line.x = line.x0;
	while (line.x != line.x1)
	{
		(line.steep) ? (pixel_to_image(env, line.y, line.x, 0xffffff)) :
		(pixel_to_image(env, line.x, line.y, 0xffffff));
		line.error = line.error + line.deltaerr;
		if (line.error > 0.5)
		{
			line.y += line.ystep;
			line.error--;
		}
		line.x++;
	}
}

void			connect_points(t_env *env)
{
	int x;
	int y;
	int x_off;
	int y_off;

	y = 0;
	x_off = get_xoff(env);
	y_off = get_yoff(env);
	while (y < env->grid.ylen)
	{
		x = 0;
		while (x < env->grid.xlen)
		{
			if (y != env->grid.ylen - 1)
			{
				line_draw(make_line(env->grid.points[y][x],
					env->grid.points[y + 1][x], x_off, y_off), env);
			}
			if (x != env->grid.xlen - 1)
				line_draw(make_line(env->grid.points[y][x],
					env->grid.points[y][x + 1], x_off, y_off), env);
			x++;
		}
		y++;
	}
}

t_env			*make_env(char *filename, int width, int height)
{
	t_env		*env;
	int			fd;

	env = malloc(sizeof(t_env));
	fd = open(filename, O_RDWR);
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, width, height, "Wireframe");
	env->img = mlx_new_image(env->mlx, width, height);
	env->data = mlx_get_data_addr(env->img, &env->bits, &env->size_line,
		&env->endian);
	env->grid = *make_grid(fd);
	env->width = width;
	env->height = height;
	env->halfhigh = (height / 2);
	env->halfwide = (width / 2);
	env->keys = make_keys();
	return (env);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_env		*env;

	if (argc != 4)
		return(0);
	fd = open(argv[1], O_RDONLY);
	env = make_env(argv[1], 1920, 1080);
	scale_xy(env->grid, SCALE);
	scale_z(env->grid, HEIGHT);
	printf("%s\n", "buttz2");
	connect_points(env);
	printf("%s\n", "buttz");
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	// printf("%s\n", "buttz73000");
	mlx_hook(env->window, 2, 0, key_press, env);
	mlx_loop(env->mlx);
	return (0);
}
