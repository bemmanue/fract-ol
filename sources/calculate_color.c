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

double	*calculate_colorstep(t_fractol *data, int r, int g, int b)
{
	double	*step;

	step = malloc(sizeof(double) * 4);
	step[0] = (double) 0x00 / data->max_iteration;
	step[1] = (double) r / data->max_iteration;
	step[2] = (double) g / data->max_iteration;
	step[3] = (double) b / data->max_iteration;
	return (step);
}

void	calculate_color(t_fractol *data)
{
	double	*colorstep;
	int		i;
	unsigned char	color[4];

	if (data->colormode % 3 == 0)
		colorstep = calculate_colorstep(data, 0xFF, 0x66, 0x99);
	else if (data->colormode % 3 == 1)
		colorstep = calculate_colorstep(data, 0x99, 0xFF, 0x66);
	else
		colorstep = calculate_colorstep(data, 0x66, 0x99, 0xFF);
	i = 0;
	while (i < 4)
	{
		data->color <<= 8;
		color[i] = *colorstep * data->iteration;
		data->color += color[i];
		colorstep++;
		i++;
	}
}
