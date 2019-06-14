/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 04:41:17 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:09:39 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	j_iter_color(t_mlx *data, double row, double col, double iteration)
{
	double new_re;
	double new_im;
	double old_re;
	double old_im;

	new_re = data->c_re_center - 2.0 / data->zoom +
		col / data->win_width * 4.0 / data->zoom;
	new_im = data->c_im_center - 1.0 / data->zoom +
		row / data->win_height * 2.0 / data->zoom;
	while (new_re * new_re + new_im * new_im < 56000 && iteration < data->iter)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = old_re * old_re - old_im * old_im + data->c_re;
		new_im = 2.0 * old_re * old_im + data->c_im;
		iteration++;
	}
	if (iteration < data->iter)
		return (mlx_get_color_value(data->mlx,
			smooth_color(iteration, new_re, new_im, data->col_scheme)));
	else
		return (mlx_get_color_value(data->mlx, 0x000000));
}

void		draw_julia(t_mlx *data)
{
	double	row;
	double	col;
	int		pixel_pt;

	pixel_pt = 0;
	row = -1;
	while (++row < data->win_height)
	{
		col = -1;
		while (++col < data->win_width)
		{
			*(unsigned int *)(data->img_data + pixel_pt *
				(data->bits_per_pixel / 8)) = j_iter_color(data, row, col, 0.0);
			pixel_pt++;
		}
	}
}

static int	b_iter_color(t_mlx *data, double row, double col, double iteration)
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
		y = 2.0 * fabs(x * y) + c_im;
		x = x_new;
		iteration++;
	}
	if (iteration < data->iter)
		return (mlx_get_color_value(data->mlx,
			smooth_color(iteration, x, y, data->col_scheme)));
	else
		return (mlx_get_color_value(data->mlx, 0x000000));
}

void		draw_burning_ship(t_mlx *data)
{
	double	row;
	double	col;
	int		pixel_pt;

	pixel_pt = 0;
	row = -1;
	while (++row < data->win_height)
	{
		col = -1;
		while (++col < data->win_width)
		{
			*(unsigned int *)(data->img_data + pixel_pt *
				(data->bits_per_pixel / 8)) = b_iter_color(data, row, col, 0.0);
			pixel_pt++;
		}
	}
}
