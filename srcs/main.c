/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 17:35:51 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:06:06 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	data;

	check_params(argc, argv, &data);
	data.mlx = mlx_init();
	init_data(&data);
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
		"fractol");
	redraw(&data);
	mlx_key_hook(data.win, key_hooks, &data);
	mlx_mouse_hook(data.win, mouse_hooks, &data);
	mlx_expose_hook(data.win, expose, &data);
	mlx_hook(data.win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
