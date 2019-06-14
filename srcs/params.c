/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 23:47:39 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:08:31 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	usage(void)
{
	ft_putendl("usage: ./fractol [fractol] [resolution]\n"
			"fractol:\n"
			"\tmandelbrot || 1\n"
			"\tjulia || 2\n"
			"\tburningship || 3\n"
			"resolution:\n"
			"\t1600x800\n"
			"\t800x400\n");
	exit(-1);
}

static int	check_fractal(char *argv, t_mlx *data)
{
	if (!ft_strcmp(argv, "mandelbrot") || !ft_strcmp(argv, "1"))
	{
		data->fractol = MANDELBROT;
		return (1);
	}
	else if (!ft_strcmp(argv, "julia") || !ft_strcmp(argv, "2"))
	{
		data->fractol = JULIA;
		return (1);
	}
	else if (!ft_strcmp(argv, "burningship") || !ft_strcmp(argv, "3"))
	{
		data->fractol = BURNING_SHIP;
		return (1);
	}
	else
		return (0);
}

static int	check_res(char *argv, t_mlx *data)
{
	if (!ft_strcmp(argv, "1600x800"))
	{
		data->res = RES_1600X800;
		return (1);
	}
	else if (!ft_strcmp(argv, "800x400"))
	{
		data->res = RES_800X400;
		return (1);
	}
	else
		return (0);
}

static void	two_param_check(char **argv, t_mlx *data)
{
	if (check_fractal(argv[1], data))
	{
		if (!check_res(argv[2], data))
			usage();
	}
	else if (check_res(argv[1], data))
	{
		if (!check_fractal(argv[2], data))
			usage();
	}
	else
		usage();
}

void		check_params(int argc, char **argv, t_mlx *data)
{
	if (argc > 3)
		usage();
	else if (argc == 3)
		two_param_check(argv, data);
	else if (argc == 2)
	{
		if (check_fractal(argv[1], data))
			data->res = RES_1600X800;
		else if (check_res(argv[1], data))
			data->fractol = MAIN_MENU;
		else
			usage();
	}
	else
	{
		data->fractol = MAIN_MENU;
		data->res = RES_1600X800;
	}
}
