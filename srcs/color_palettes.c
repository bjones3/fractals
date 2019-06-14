/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 19:02:17 by bjones            #+#    #+#             */
/*   Updated: 2017/10/15 02:09:54 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	palette(int rem)
{
	if (rem == 12)
		return (0xCB9018);
	else if (rem == 13)
		return (0xA8740B);
	else if (rem == 0)
		return (0x775000);
	else
		return (0x4D3400);
}

int			color_palette(int nbr)
{
	int rem;

	rem = nbr % 14;
	if (rem == 2)
		return (0x0C002A);
	else if (rem == 3)
		return (0x01004C);
	else if (rem == 4)
		return (0x020167);
	else if (rem == 5)
		return (0x16469E);
	else if (rem == 6)
		return (0x3165C8);
	else if (rem == 7)
		return (0x9DB8E9);
	else if (rem == 8)
		return (0xD6E8FF);
	else if (rem == 9)
		return (0xFFF3D6);
	else if (rem == 10)
		return (0xEFD38F);
	else if (rem == 11)
		return (0xF2B63C);
	else
		return (palette(rem));
}

static int	palette2(int rem)
{
	if (rem == 12)
		return (0x62477C);
	else if (rem == 13)
		return (0xAF97C7);
	else if (rem == 0)
		return (0xF0E0FF);
	else
		return (0xFFCACA);
}

int			color_palette2(int nbr)
{
	int rem;

	rem = nbr % 14;
	if (rem == 2)
		return (0xA61C44);
	else if (rem == 3)
		return (0xCD3E67);
	else if (rem == 4)
		return (0xEA7194);
	else if (rem == 5)
		return (0xFFA6C0);
	else if (rem == 6)
		return (0xFE9CF6);
	else if (rem == 7)
		return (0xEB66E0);
	else if (rem == 8)
		return (0xCB3EBF);
	else if (rem == 9)
		return (0x9C2192);
	else if (rem == 10)
		return (0x710769);
	else if (rem == 11)
		return (0x40116F);
	else
		return (palette2(rem));
}

int			color_palette3(int nbr)
{
	int rem;

	rem = nbr % 14;
	if (rem == 1 || rem == 8)
		return (0xFF0400);
	else if (rem == 2 || rem == 9)
		return (0xFF9700);
	else if (rem == 3 || rem == 10)
		return (0xFFEC00);
	else if (rem == 4 || rem == 11)
		return (0x1BFF00);
	else if (rem == 5 || rem == 12)
		return (0x00FFF3);
	else if (rem == 6 || rem == 13)
		return (0x0032FF);
	else
		return (0xE400FF);
}
