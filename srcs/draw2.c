/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 04:45:57 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:06:53 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	color_interpolate(int color1, int color2, double fraction)
{
	t_color col1;
	t_color col2;
	t_color new;

	col1.r = (color1 >> 16) & 0xFF;
	col1.g = (color1 >> 8) & 0xFF;
	col1.b = color1 & 0xFF;
	col2.r = (color2 >> 16) & 0xFF;
	col2.g = (color2 >> 8) & 0xFF;
	col2.b = color2 & 0xFF;
	new.r = fraction * (col2.r - col1.r) + col1.r;
	new.g = fraction * (col2.g - col1.g) + col1.g;
	new.b = fraction * (col2.b - col1.b) + col1.b;
	return ((new.r << 16) | (new.g << 8) | (new.b));
}

int			smooth_color(double iteration, double x, double y, int color_scheme)
{
	double	log_zn;
	double	nu;
	int		color1;
	int		color2;

	log_zn = log(x * x + y * y) / 2.0;
	nu = log(log_zn / log(2.0)) / log(2.0);
	iteration = iteration + 1.0 - nu;
	if (color_scheme == 1)
	{
		color1 = color_palette(floor(iteration));
		color2 = color_palette(floor(iteration) + 1.0);
	}
	if (color_scheme == 2)
	{
		color1 = color_palette2(floor(iteration));
		color2 = color_palette2(floor(iteration) + 1.0);
	}
	if (color_scheme == 3)
	{
		color1 = color_palette3(floor(iteration));
		color2 = color_palette3(floor(iteration) + 1.0);
	}
	return (color_interpolate(color1, color2, iteration - floor(iteration)));
}

static int	m_iter_color(t_mlx *data, double row, double col, double iteration)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double x_new;

	c_re = data->c_re_center - 2.0 / data->zoom +
		col / data->win_width * 4.0 / data->zoom;
	c_im = data->c_im_center - 1.0 / data->zoom +
		row / data->win_height * 2.0 / data->zoom;
	x = 0.0;
	y = 0.0;
	while (x * x + y * y < 56000 && iteration < data->iter)
	{
		x_new = x * x - y * y + c_re;
		y = 2.0 * x * y + c_im;
		x = x_new;
		iteration++;
	}
	if (iteration < data->iter)
		return (mlx_get_color_value(data->mlx,
			smooth_color(iteration, x, y, data->col_scheme)));
	else
		return (mlx_get_color_value(data->mlx, 0x000000));
}

void		draw_mandelbrot(t_mlx *data)
{
	double	row;
	double	col;
	int		pixel_pt;

	row = -1;
	pixel_pt = 0;
	while (++row < data->win_height)
	{
		col = -1;
		while (++col < data->win_width)
		{
			*(unsigned int *)(data->img_data + pixel_pt *
			(data->bits_per_pixel / 8)) = m_iter_color(data, row, col, 0.0);
			pixel_pt++;
		}
	}
}
