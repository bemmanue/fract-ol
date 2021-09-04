/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:14:17 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/04 11:14:20 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	init_complex(double re, double im)
{
	t_comp complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	pixel_put(t_fractol *data, int x, int y, int color)
{
	char *dst;

	if (data->x < WIDTH && data->y < WIDTH)
	{
		dst = data->addr + (y * data->sl + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	draw_image(t_fractol *data)
{
	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		data->c.im = (data->centre.im - data->y) * data->ratio.im;
		while (data->x < WIDTH)
		{
			data->iteration = 0;
			data->color = 0x00000000;
			data->c.re = (data->x - data->centre.re) * data->ratio.re;
			data->z = init_complex(data->c.re, data->c.im);
			(data->calculate)(data);
			calculate_color(data);
			if (data->iteration != MAX_ITERATION)
				pixel_put(data, data->x, data->y, data->color);
			else
				pixel_put(data, data->x, data->y, 0x00000000);
			data->x++;
		}
		data->y++;
	}
	return (0);
}