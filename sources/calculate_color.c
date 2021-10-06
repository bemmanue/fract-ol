/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:42:37 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/11 18:42:40 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int calculate_color(t_fractol *data)
{
	int color;
	unsigned char	c;

	color = 0;
	color <<= 8;
	c = data->color.red * data->iteration;
	color += c;
	color <<= 8;
	c = data->color.green * data->iteration;
	color += c;
	color <<= 8;
	c = data->color.blue * data->iteration;
	color += c;
	return (color);
}

void	calculate_colorstep(t_fractol *data)
{
	int r;
	int g;
	int b;

	if (data->colormode % 3 == 0)
	{
		r = 0xFF;
		g = 0x66;
		b = 0x99;
	}
	else if (data->colormode % 3 == 1)
	{
		r = 0x99;
		g = 0xFF;
		b = 0x66;
	}
	else
	{
		r = 0x66;
		g = 0x99;
		b = 0xFF;
	}
	data->color.red = (double) r / data->max_iteration;
	data->color.green = (double) g / data->max_iteration;
	data->color.blue = (double) b / data->max_iteration;
}
