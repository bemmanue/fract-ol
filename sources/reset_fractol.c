/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:44:28 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/11 18:44:31 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_fractol(t_fractol *data)
{
	data->centre.re = WIDTH / 2;
	data->centre.im = HEIGHT / 2;
	data->min = init_complex(-2.0, -2.0);
	data->max.re = 2.0;
	data->max.im = data->min.im
		+ (data->max.re - data->min.re) * HEIGHT / WIDTH;
	data->ratio.re = (data->max.re - data->min.re) / WIDTH;
	data->ratio.im = (data->max.im - data->min.im) / HEIGHT;
	data->k = init_complex(0.4, 0.4);
	data->fixed_julia = 1;
	data->max_iteration = MAX_ITERATION;
	data->colormode = 0;
	calculate_colorstep(data);
}
