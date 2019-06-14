/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 04:17:28 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:08:57 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	change_res(t_mlx *data)
{
	if (data->res == RES_1600X800)
		data->res = RES_800X400;
	else
		data->res = RES_1600X800;
	if (data->res == RES_1600X800)
	{
		data->win_width = 1600;
		data->win_height = 800;
	}
	else
	{
		data->win_width = 800;
		data->win_height = 400;
	}
	mlx_destroy_window(data->mlx, data->win);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
		"fractol");
	mlx_key_hook(data->win, key_hooks, data);
	mlx_mouse_hook(data->win, mouse_hooks, data);
	mlx_expose_hook(data->win, expose, data);
	mlx_hook(data->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move_hook, data);
}

static void	main_menu_mouse(int button, int x, int y, t_mlx *data)
{
	if (button == 1)
	{
		if ((x >= 662 / data->res) && (x <= 662 / data->res + data->btn_width)
		&& (y >= 450 / data->res) && (y <= 450 / data->res + data->btn_height))
			data->fractol = MANDELBROT;
		if ((x >= 662 / data->res) && (x <= 662 / data->res + data->btn_width)
		&& (y >= 550 / data->res) && (y <= 550 / data->res + data->btn_height))
			data->fractol = JULIA;
		if ((x >= 662 / data->res) && (x <= 662 / data->res + data->btn_width)
		&& (y >= 650 / data->res) && (y <= 650 / data->res + data->btn_height))
			data->fractol = BURNING_SHIP;
		if ((x >= 50 / data->res) && (x <= 50 / data->res + data->btn_width)
		&& (y >= 700 / data->res) && (y <= 700 / data->res + data->btn_height))
			change_res(data);
		init_data(data);
	}
}

static void	zoom(t_mlx *data, int x, int y, int in_out)
{
	if (in_out)
	{
		data->zoom *= 1.5;
		data->iter += 3;
	}
	else
	{
		data->zoom /= 1.5;
		data->iter -= 3;
	}
	data->c_re_center = data->c_re_center - 2.0 / data->zoom
		+ x / (double)data->win_width * 4.0 / data->zoom;
	data->c_im_center = data->c_im_center - 1.0 / data->zoom
		+ y / (double)data->win_height * 2.0 / data->zoom;
}

int			mouse_hooks(int button, int x, int y, t_mlx *data)
{
	if (data->fractol == MAIN_MENU)
		main_menu_mouse(button, x, y, data);
	else if (button == 5 || button == 1)
	{
		if ((button == 1) && (x >= 10 / data->res) && (x <= 10 /
		data->res + data->btn_width) && (y >= 10 / data->res) &&
		(y <= 10 / data->res + data->btn_height))
			data->fractol = MAIN_MENU;
		else
			zoom(data, x, y, 1);
	}
	else if (button == 4 || button == 2)
		zoom(data, x, y, 0);
	else
		return (0);
	redraw(data);
	return (0);
}

int			mouse_move_hook(int x, int y, t_mlx *data)
{
	if (x < 0 || x >= data->win_width || y < 0 || y >= data->win_height ||
			!data->julia_toggle)
		return (0);
	data->c_re = -2.0 + 3.0 * (x / (double)data->win_width);
	data->c_im = -1.0 + 2.0 * (y / (double)data->win_height);
	redraw(data);
	return (0);
}
