/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:14:29 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/04 11:14:31 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_name(const char *s1, const char *s2)
{
	unsigned char	another_register;

	while (*s1)
	{
		if (*s2 >= 'A' && *s2 <= 'Z')
			another_register = *s2 + 32;
		else if (*s2 >= 'a' && *s2 <= 'z')
			another_register = *s2 - 32;
		else
			return (0);
		if (*s1 != *s2 && *s1 != another_register)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

t_fractol	*fill_data(char *name, void (*calculate)(t_fractol *))
{
	t_fractol	*data;

	data = malloc(sizeof(t_fractol));
	if (!data)
		return (NULL);
	data->name = name;
	data->calculate = calculate;
	data->julia_motion = julia_motion;
	data->help = 0;
	data->fixed_julia = 1;
	data->centre.re = WIDTH / 2;
	data->centre.im = HEIGHT / 2;
	data->min = init_complex(-2.0, -2.0);
	data->max.re = 2.0;
	data->max.im = data->min.im
		+ (data->max.re - data->min.re) * HEIGHT / WIDTH;
	data->ratio.re = (data->max.re - data->min.re) / WIDTH;
	data->ratio.im = (data->max.im - data->min.im) / HEIGHT;
	data->k = init_complex(0.4, 0.4);
	data->max_iteration = MAX_ITERATION;
	data->colormode = 0;
	calculate_colorstep(data);
	return (data);
}

t_fractol	*init_fractol(char *name)
{
	t_fractol	*data;

	data = NULL;
	if (check_name("Mandelbrot", name))
		data = fill_data("Mandelbrot", &mandelbrot);
	else if (check_name("Julia", name))
		data = fill_data("Julia", &julia);
	else if (check_name("Burningship", name))
		data = fill_data("Burningship", &burningship);
	else
		print_help();
	return (data);
}
