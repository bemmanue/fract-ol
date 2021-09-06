/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:14:40 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/04 11:14:43 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	julia(t_fractol *data)
{
	while (pow(data->z.re, 2.0) + pow(data->z.im, 2.0) <= 4 &&
	data->iteration < data->max_iteration)
	{
		data->z = init_complex(
				pow(data->z.re, 2.0) - pow(data->z.im, 2.0) + data->k.re,
				2.0 * data->z.re * data->z.im + data->k.im);
		data->iteration++;
		data->color += data->color_step;
	}
}
