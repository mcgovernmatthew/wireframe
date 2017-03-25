/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcgover <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:33:07 by mmcgover          #+#    #+#             */
/*   Updated: 2017/03/24 19:33:09 by mmcgover         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <math.h>
#include <mlx.h>
#include "fdf.h"

typedef struct					s_line
{
	int							x0;
	int							y0;
	int							x1;
	int							y1;
	float						deltax;
	float						deltay;
	float						error;
	float						deltaerr;
	int							ystep;
	int							steep;
	int							y;
	int							x;
}								t_line;

typedef	struct					s_point
{
	float						x;
	float						y;
	float						z;
}								t_point;

typedef struct					s_keys
{
	int							w;
	int							a;
	int							s;
	int							d;
	int							q;
	int							e;
	int							plus;
	int							minus;
}								t_keys;

typedef	struct					s_rot
{
	double						x;
	double						y;
	double						z;
	double						d;
	double						theta;
}								t_rot;

typedef struct					s_grid
{
	int							xy_scale;
	int							z_scale;
	int							xlen;
	int							ylen;
	t_point						**points;
}								t_grid;

typedef struct					s_img
{
	void						*img;
	char						*data;
	int							bits;
	int							size_line;
	int							endian;
	int							height;
	int							width;
}								t_img;

typedef struct 					s_env
{
	t_keys						keys;
	void						*mlx;
	void						*window;
	t_grid						grid;
	int							width;
	int							height;
	int							halfwide;
	int							halfhigh;
	t_img						*img;
	char						*data;
	int							bits;
	int							size_line;
	int							endian;
}								t_env;

void							pixel_to_image(t_env *env, int x, int y, int color);
t_point							**make_points(char *buff, int xlen, int ylen);
t_grid							*make_grid(int fd);
t_point							set_point(float x, float y, float z);
void							line_draw(t_line line, t_env *env);
float							mean_x(t_grid grid);
float							mean_y(t_grid grid);
float							mean_z(t_grid grid);
void 							rotate_x(t_grid grid, float radians);
void 							rotate_y(t_grid grid, float radians);
void 							rotate_z(t_grid grid, float radians);
t_line							make_line(t_point start, t_point end, int xoff, int yoff);
void 							scale_z(t_grid grid, float scale);
void							scale_xy(t_grid grid, float scale);
int								get_xoff(t_env *env);
int								get_yoff(t_env *env);
void							connect_points(t_env *env);
t_keys							make_keys(void);
int 							key_press(int keycode, t_env *env);
t_env							*make_env(char *filename, int width, int height);
t_point							get_center(t_grid grid);

#endif
