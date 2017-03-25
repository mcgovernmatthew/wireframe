/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcgover <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:27:06 by mmcgover          #+#    #+#             */
/*   Updated: 2017/03/24 19:27:07 by mmcgover         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			**make_points(char *buff, int xlen, int ylen)
{
	int			i;
	int			x;
	int			y;
	char		**split;
	t_point	**points;

	split = ft_strsplit(buff, ' ');
	points = (t_point **)malloc(sizeof(t_point *) * ylen);
	i = 0;
	y = 0;
	while (y < ylen)
	{
		x = 0;
		points[y] = (t_point *)malloc(sizeof(t_point) * xlen);
		while (x < xlen)
		{
			points[y][x].x = x;
			points[y][x].y = y;
			points[y][x].z = ft_atoi(split[i++]);
			x++;
		}
		y++;
	}
	return(points);
}

t_grid			*make_grid(int fd)
{
	char		*buff;
	char		*line;
	int			ylen;
	int			xlen;
	t_grid		*grid;

	xlen = 0;
	ylen = 0;
	buff = "";
	grid = (t_grid *)malloc(sizeof(t_grid));
	while (get_next_line(fd, &line))
	{
		buff = ft_strjoin(ft_strjoin(buff, " "), line);
		if (xlen == 0)
			xlen = ft_wordcount(line, ' ');
		if (xlen != ft_wordcount(line, ' '))
		{
			printf("%s\n", "parameters are invalid");
			grid = 0;
			return (grid);
		}
		ylen++;
	}
	grid->points = make_points(buff, xlen, ylen);
	grid->xlen = xlen;
	grid->ylen = ylen;
	return (grid);
}
