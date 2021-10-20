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

static unsigned char calculate_end(t_fractol *data)
{
	unsigned char	c;
	int 			check;
	double			q;
	double			k;

	c = 0;
	q = data->max_iteration / 5.0;
	k = data->max_iteration - q;
	if (data->iteration > q && data->iteration <= q * 2.0)
		c = 0xFF;
	else if (data->iteration <= q * 3.0 && data->iteration > q * 2.0)
	{
		check = (char) data->color.blue * (q * 3.0 - data->iteration);
		c = (char) data->color.blue * (q * 3.0 - data->iteration);
		if (check > 0xFF)
			c = 0xFF;
	}
	else if (data->iteration <= q)
	{
		check = data->color.red * data->iteration;
		c = (char) data->color.red * data->iteration;
		if (check > 0xFF)
			c = 0xFF;
	}
	return (c);
}

static unsigned char calculate_middle(t_fractol *data)
{
	unsigned char	c;
	int				check;
	double			q;
	double			k;

	c = 0;
	q = data->max_iteration / 5.0;
	k = data->max_iteration - q;
	if (data->iteration <= k && data->iteration > q * 2.0)
		c = 0xFF;
	else if (data->iteration >= k)
	{
		check = (char) data->color.green * (data->max_iteration - data->iteration);
		c = (char) data->color.green * (data->max_iteration - data->iteration);
		if (check > 0xFF)
			c = 0xFF;
	}
	if (data->iteration > q && data->iteration <= q * 2.0)
	{
		check = (char) data->color.green * (q + (data->iteration - q * 2.0));
		c = (char) data->color.green * (q + (data->iteration- q * 2.0));
		if (check > 0xFF)
			c = 0xFF;
	}
	return (c);
}

static unsigned char calculate_center(t_fractol *data)
{
	unsigned char	c;
	int				check;
	double			q;
	double			k;

	c = 0;
	q = data->max_iteration / 5.0;
	k = data->max_iteration - q;

	if (data->iteration > k)
		c = 0xFF;
	else if (data->iteration <= k && data->iteration > q * 3.0)
	{
		check = data->color.red * (data->iteration - q * 3.0);
		c = (char) data->color.red * (data->iteration - q * 3.0);
		if (check > 0xFF)
			c = 0xFF;
	}
	return (c);
}

static int	calculate_third(t_fractol *data)
{
	int				color;

	color = 0;
	color <<= 8;
	color += calculate_middle(data);
	color <<= 8;
	color += calculate_end(data);
	color <<= 8;
	color += calculate_center(data);
	return (color);
}

static int	calculate_second(t_fractol *data)
{
	int				color;

	color = 0;
	color <<= 8;
	color += calculate_end(data);
	color <<= 8;
	color += calculate_center(data);
	color <<= 8;
	color += calculate_middle(data);
	return (color);
}

static int	calculate_first(t_fractol *data)
{
	int				color;

	color = 0;
	color <<= 8;
	color += calculate_center(data);
	color <<= 8;
	color += calculate_middle(data);
	color <<= 8;
	color += calculate_end(data);
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
	double	q;
	int		i;

	i = 0;
	q = data->max_iteration / 5.0;
	data->color.red = (double) 0xFF / q;
	data->color.green = (double) 0xFF / q;
	data->color.blue = (double) 0xFF / q;
}
