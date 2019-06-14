/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:20:03 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 05:11:31 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <get_next_line.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define RES_1600X800 1
# define RES_800X400 2

# define NUMPAD_PLUS 69
# define NUMPAD_MINUS 78
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define ESC 53
# define NUM_ONE 18
# define NUM_TWO 19
# define NUM_THREE 20
# define SPACE_BAR 49
# define RESET 15

# define MAIN_MENU 0
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct	s_mlx
{
	int			win_width;
	int			win_height;
	void		*img;
	char		*img_data;
	int			bits_per_pixel;
	void		*mlx;
	void		*win;
	int			iter;
	double		zoom;
	double		c_re_center;
	double		c_im_center;
	int			fractol;
	double		c_re;
	double		c_im;
	int			res;
	int			col_scheme;
	int			btn_width;
	int			btn_height;
	int			julia_toggle;
}				t_mlx;

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;

/*
** PARAMS
*/
void			check_params(int argc, char **argv, t_mlx *data);

/*
** INITIALIZATION
*/
void			init_data(t_mlx *data);

/*
** MAIN MENU
*/
void			draw_main_menu(t_mlx *data);
void			draw_menu_btn(t_mlx *data);

/*
** MOUSE HOOKS
*/
int				mouse_hooks(int button, int x, int y, t_mlx *data);
int				mouse_move_hook(int x, int y, t_mlx *data);

/*
** KEY HOOKS
*/
int				key_hooks(int keycode, t_mlx *data);

/*
** REDRAW
*/
void			redraw(t_mlx *data);
int				expose(t_mlx *data);

/*
** DRAW1
*/
void			draw_julia(t_mlx *data);
void			draw_burning_ship(t_mlx *data);

/*
** DRAW2
*/
void			draw_mandelbrot(t_mlx *data);
int				smooth_color(double iteration,
				double x, double y, int color_scheme);

/*
** COLOR PALETTES
*/
int				color_palette(int nbr);
int				color_palette2(int nbr);
int				color_palette3(int nbr);

#endif
