/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:14:51 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/04 11:14:55 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	mandelbrot(t_fractol *data)
{
	while (pow(data->z.re, 2.0) + pow(data->z.im, 2.0) <= 4 &&
	data->iteration < MAX_ITERATION)
	{
		data->z = init_complex(
				pow(data->z.re, 2.0) - pow(data->z.im, 2.0) +
				data->c.re,
				2.0 * data->z.re * data->z.im + data->c.im);
		data->iteration++;
		data->color += data->color_step;
	}
}