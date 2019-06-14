/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 04:36:16 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:09:17 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	write_strings2(t_mlx *data)
{
	mlx_string_put(data->mlx, data->win, 595, 5, 0xFFFFFF,
		"PRESS 1 FOR GOLD");
	mlx_string_put(data->mlx, data->win, 595, 25, 0xFFFFFF,
		"PRESS 2 FOR LOVE");
	mlx_string_put(data->mlx, data->win, 595, 45, 0xFFFFFF,
		"PRESS 3 FOR RAINBOWS");
	mlx_string_put(data->mlx, data->win, 5, 335, 0xFFFFFF,
		"ITER +: (NUMPAD +)");
	mlx_string_put(data->mlx, data->win, 5, 355, 0xFFFFFF,
		"ITER -: (NUMPAD -)");
	mlx_string_put(data->mlx, data->win, 645, 315, 0xFFFFFF,
		"ZOOM: (LMB/RMB)");
	mlx_string_put(data->mlx, data->win, 705, 335, 0xFFFFFF,
		"(M WHEEL)");
	mlx_string_put(data->mlx, data->win, 555, 355, 0xFFFFFF,
		"PAN SCREEN: (ARROW KEYS)");
	mlx_string_put(data->mlx, data->win, 695, 295, 0xFFFFFF,
		"RESET: (R)");
	mlx_string_put(data->mlx, data->win, 5, 375, 0xFFFFFF,
		"ITERATION COUNT: ");
	mlx_string_put(data->mlx, data->win, 185, 375, 0xFFFFFF,
		ft_itoa(data->iter));
	if (data->fractol == JULIA)
		mlx_string_put(data->mlx, data->win, 525, 375, 0xFFFFFF,
		"SPACE BAR: INTERACTIVE MODE");
}

static void	write_strings(t_mlx *data)
{
	mlx_string_put(data->mlx, data->win, 1350, 10, 0xFFFFFF,
		"PRESS 1 FOR GOLD");
	mlx_string_put(data->mlx, data->win, 1350, 30, 0xFFFFFF,
		"PRESS 2 FOR LOVE");
	mlx_string_put(data->mlx, data->win, 1350, 50, 0xFFFFFF,
		"PRESS 3 FOR RAINBOWS");
	mlx_string_put(data->mlx, data->win, 1290, 100, 0xFFFFFF,
		"INCREASE ITERATION: (NUMPAD +)");
	mlx_string_put(data->mlx, data->win, 1290, 120, 0xFFFFFF,
		"DECREASE ITERATION: (NUMPAD -)");
	mlx_string_put(data->mlx, data->win, 1290, 140, 0xFFFFFF,
		"PAN SCREEN: (ARROW KEYS)");
	mlx_string_put(data->mlx, data->win, 1290, 160, 0xFFFFFF,
		"ZOOM IN/OUT: (LEFT/RIGHT CLICK)");
	mlx_string_put(data->mlx, data->win, 1420, 180, 0xFFFFFF,
		"(MOUSE WHEEL)");
	mlx_string_put(data->mlx, data->win, 1290, 200, 0xFFFFFF,
		"RESET: (R)");
	mlx_string_put(data->mlx, data->win, 50, 770, 0xFFFFFF,
		"ITERATION COUNT: ");
	mlx_string_put(data->mlx, data->win, 230, 770, 0xFFFFFF,
		ft_itoa(data->iter));
	if (data->fractol == JULIA)
		mlx_string_put(data->mlx, data->win, 1150, 770, 0xFFFFFF,
		"PRESS SPACE BAR TO TOGGLE INTERACTIVE MODE");
}

void		redraw(t_mlx *data)
{
	int			size_line;
	int			endian;

	if (data->fractol == 0)
	{
		draw_main_menu(data);
		return ;
	}
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->img_data = mlx_get_data_addr(data->img,
		&data->bits_per_pixel, &size_line, &endian);
	if (data->fractol == MANDELBROT)
		draw_mandelbrot(data);
	if (data->fractol == JULIA)
		draw_julia(data);
	if (data->fractol == BURNING_SHIP)
		draw_burning_ship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	draw_menu_btn(data);
	if (data->res == RES_1600X800)
		write_strings(data);
	else
		write_strings2(data);
}

int			expose(t_mlx *data)
{
	redraw(data);
	return (0);
}
