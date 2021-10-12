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

static int	calculate_third(t_fractol *data)
{
	int				color;
	unsigned char	c;
	int				i;

	color = 0;
	i = 2 * (data->iteration - (data->max_iteration / 2));
	color <<= 8;
	c = data->color.red * data->iteration;
	color += c;
	if (data->iteration > data->max_iteration / 2)
	{
		c = data->color.red * (data->iteration - (data->max_iteration / 2));
		color -= c;
	}
	color <<= 8;
	c = data->color.green * data->iteration;
	color += c;
	color <<= 8;
	if (data->iteration > data->max_iteration / 2)
	{
		c = data->color.blue * i;
		color += c;
	}
	return (color);
}

static int	calculate_second(t_fractol *data)
{
	int				color;
	unsigned char	c;
	int				i;

	color = 0;
	i = 2 * (data->iteration - (data->max_iteration / 2));
	color <<= 8;
	c = data->color.red * data->iteration;
	color += c;
	if (data->iteration > data->max_iteration / 2)
	{
		c = data->color.red * (data->iteration - (data->max_iteration / 2));
		color -= c;
	}
	color <<= 8;
	if (data->iteration > data->max_iteration / 2)
	{
		c = data->color.green * i;
		color += c;
	}
	color <<= 8;
	c = data->color.blue * data->iteration;
	color += c;
	return (color);
}

static int	calculate_first(t_fractol *data)
{
	int				color;
	unsigned char	c;
	int				i;

	color = 0;
	i = 2 * (data->iteration - (data->max_iteration / 2));
	color <<= 8;
	if (data->iteration > data->max_iteration / 2)
	{
		c = data->color.red * i;
		color += c;
	}
	color <<= 8;
	c = data->color.green * data->iteration;
	color += c;
	if (data->iteration > data->max_iteration / 2)
	{
		c = data->color.green * (data->iteration - (data->max_iteration / 2));
		color -= c;
	}
	color <<= 8;
	c = data->color.blue * data->iteration;
	color += c;
	return (color);
}

int	calculate_color(t_fractol *data)
{
	int				color;

	color = 0;
	if (data->colormode % 3 == 0)
		color = calculate_first(data);
	else if (data->colormode % 3 == 1)
		color = calculate_second(data);
	else if (data->colormode % 3 == 2)
		color = calculate_third(data);
	return (color);
}

void	calculate_colorstep(t_fractol *data)
{
	int	r;
	int	g;
	int	b;

	r = 0xFF;
	g = 0xFF;
	b = 0xFF;
	data->color.red = (double) r / data->max_iteration;
	data->color.green = (double) g / data->max_iteration;
	data->color.blue = (double) b / data->max_iteration;
}
