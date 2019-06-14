/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 04:26:15 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:08:39 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_ship(t_mlx *data)
{
	data->iter = 36;
	data->zoom = 17.085938;
	data->c_re_center = -1.689757;
	data->c_im_center = -0.034212;
}

void		init_data(t_mlx *data)
{
	data->iter = 50;
	data->zoom = 1.0;
	data->c_re_center = 0.0;
	data->c_im_center = 0.0;
	if (data->fractol == BURNING_SHIP)
		init_ship(data);
	data->julia_toggle = 0;
	data->c_re = -0.7;
	data->c_im = 0.27015;
	data->col_scheme = 1;
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
}
