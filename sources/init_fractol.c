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

	while (*s1 && *s2)
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
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (NULL);
	fractol->name = name;
	fractol->calculate = calculate;
	fractol->centre.re = WIDTH / 2;
	fractol->centre.im = HEIGHT / 2;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im +
			(fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->ratio.re = (fractol->max.re - fractol->min.re) / WIDTH;
	fractol->ratio.im = (fractol->max.im - fractol->min.im) / HEIGHT;
	fractol->k = init_complex(0.3, 0.4);
	fractol->colormode = 0;
	calculate_color(fractol);
	return (fractol);
}

t_fractol	*init_fractol(char *name)
{
	t_fractol	*fractol;

	if (check_name("Mandelbrot", name))
		fractol = fill_data("Mandelbrot", &mandelbrot);
	else if (check_name("Julia", name))
		fractol = fill_data("Julia", &julia);
	else if (check_name("Burningship", name))
		fractol = fill_data("Burningship", &burningship);
	else
		fractol = NULL;
	return (fractol);
}
