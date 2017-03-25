/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcgover <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:27:34 by mmcgover          #+#    #+#             */
/*   Updated: 2017/03/24 19:27:34 by mmcgover         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_keys			make_keys(void)
{
	t_keys 		keys;

	keys.w = 0;
	keys.a = 0;
	keys.s = 0;
	keys.d = 0;
	return (keys);
}

int 			key_press(int keycode, t_env *env)
{
	// printf("key_press: %i\n", keycode);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->data = mlx_get_data_addr(env->img, &env->bits, &env->size_line,
		&env->endian);
	printf("key_press: %i\n", keycode);
	if (keycode == 126)
		rotate_x(env->grid, -.072);
	if (keycode == 125)
		rotate_x(env->grid, .072);
	if (keycode == 124)
		rotate_y(env->grid, .072);
	if (keycode == 123)
		rotate_y(env->grid, -.072);
		if (keycode == 53)
			exit(1);
	connect_points(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	return (keycode);
}
