/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcgover <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:27:15 by mmcgover          #+#    #+#             */
/*   Updated: 2017/03/24 19:27:17 by mmcgover         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_image(t_line line, t_env *env)
{
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
	(line.steep) ? (pixel_to_image(env, line.y, line.x, 0xffffff)) :
		(pixel_to_image(env, line.x, line.y, 0xffffff));
}

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
