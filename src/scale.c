/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcgover <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:27:22 by mmcgover          #+#    #+#             */
/*   Updated: 2017/03/24 19:27:23 by mmcgover         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
