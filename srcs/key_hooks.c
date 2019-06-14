/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 04:33:54 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 04:34:52 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	basic_keys(int keycode, t_mlx *data)
{
	if (keycode == NUMPAD_PLUS || keycode == 24)
		data->iter += 5;
	else if (keycode == NUMPAD_MINUS || keycode == 27)
		data->iter -= 5;
	else if (keycode == ARROW_LEFT)
		data->c_re_center -= 1 / data->zoom;
	else if (keycode == ARROW_RIGHT)
		data->c_re_center += 1 / data->zoom;
	else if (keycode == ARROW_DOWN)
		data->c_im_center += 1 / data->zoom;
	else if (keycode == ARROW_UP)
		data->c_im_center -= 1 / data->zoom;
	else if (keycode == NUM_ONE || keycode == 83)
		data->col_scheme = 1;
	else if (keycode == NUM_TWO || keycode == 84)
		data->col_scheme = 2;
	else if (keycode == NUM_THREE || keycode == 85)
		data->col_scheme = 3;
	else
		return (0);
	return (1);
}

int			key_hooks(int keycode, t_mlx *data)
{
	if (keycode == SPACE_BAR && data->fractol == JULIA)
	{
		if (data->julia_toggle == 0)
			data->julia_toggle = 1;
		else
			data->julia_toggle = 0;
	}
	else if (keycode == RESET)
		init_data(data);
	else if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (!basic_keys(keycode, data))
		return (0);
	redraw(data);
	return (0);
}
