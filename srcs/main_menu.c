/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:35:01 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:09:54 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_mm_1600x800(t_mlx *data)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(data->mlx,
		"imgs/main_menu_bg_16x8.xpm", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/ff_16x8.xpm", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (1600 - w) / 2, 200);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_m_16x8.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (1600 - w) / 2, 450);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_j_16x8.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (1600 - w) / 2, 550);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_bs_16x8.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (1600 - w) / 2, 650);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_res_16x8.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, 50, 700);
	mlx_destroy_image(data->mlx, img);
	data->btn_width = w;
	data->btn_height = h;
}

static void	draw_mm_800x400(t_mlx *data)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(data->mlx,
		"imgs/main_menu_bg_8x4.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/ff_8x4.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (800 - w) / 2, 100);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_m_8x4.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (800 - w) / 2, 225);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_j_8x4.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (800 - w) / 2, 275);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_bs_8x4.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, (800 - w) / 2, 325);
	mlx_destroy_image(data->mlx, img);
	img = mlx_xpm_file_to_image(data->mlx, "imgs/btn_res_8x4.XPM", &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, img, 25, 350);
	mlx_destroy_image(data->mlx, img);
	data->btn_width = w;
	data->btn_height = h;
}

void		draw_main_menu(t_mlx *data)
{
	if (data->res == RES_1600X800)
		draw_mm_1600x800(data);
	else
		draw_mm_800x400(data);
}

void		draw_menu_btn(t_mlx *data)
{
	void	*menu_btn;
	int		width;
	int		height;

	if (data->res == RES_1600X800)
	{
		menu_btn = mlx_xpm_file_to_image(data->mlx,
			"imgs/btn_mm_16x8.XPM", &width, &height);
		mlx_put_image_to_window(data->mlx, data->win, menu_btn, 10, 10);
	}
	if (data->res == RES_800X400)
	{
		menu_btn = mlx_xpm_file_to_image(data->mlx,
			"imgs/btn_mm_8x4.XPM", &width, &height);
		mlx_put_image_to_window(data->mlx, data->win, menu_btn, 5, 5);
	}
	mlx_destroy_image(data->mlx, menu_btn);
	data->btn_width = width;
	data->btn_height = height;
}
