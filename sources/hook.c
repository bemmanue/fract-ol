/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:13:47 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/04 11:13:51 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_color(t_fractol *data)
{
	double   		step[4];
	int             i;
	unsigned char	color[4];
	int				color_step;

	color_step = 0x0;
	if (data->colormode % 3 == 0)
	{
		step[0] = (double) 0x00 / MAX_ITERATION;
		step[1] = (double) 0x00 / MAX_ITERATION;
		step[2] = (double) 0x00 / MAX_ITERATION;
		step[3] = (double) 0xFF / MAX_ITERATION;
	}
	else if (data->colormode % 3 == 1)
	{
		step[0] = (double) 0x00 / MAX_ITERATION;
		step[1] = (double) 0x00 / MAX_ITERATION;
		step[2] = (double) 0xFF / MAX_ITERATION;
		step[3] = (double) 0x00 / MAX_ITERATION;
	}
	else if (data->colormode % 3 == 2)
	{
		step[0] = (double) 0x00 / MAX_ITERATION;
		step[1] = (double) 0xFF / MAX_ITERATION;
		step[2] = (double) 0x00 / MAX_ITERATION;
		step[3] = (double) 0x00 / MAX_ITERATION;
	}
	color[0] = step[0] * data->iteration;
	color[1] = step[1] * data->iteration;
	color[2] = step[2] * data->iteration;
	color[3] = step[3] * data->iteration;
	i = 0;
	while (i <= 3)
	{
		color_step <<= 8;
		color_step += color[i];
		i++;
	}
	data->color = color_step;
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == ESCAPE)
		exit(0);
	else if (keycode == SPACEBAR)
	    data->colormode++;
	else if (keycode == KEY_UP)
		data->centre.im += 20;
	else if (keycode == KEY_DOWN)
		data->centre.im -= 20;
	else if (keycode == KEY_RIGHT)
		data->centre.re -= 20;
	else if (keycode == KEY_LEFT)
		data->centre.re += 20;
	mlx_destroy_image(data->mlx, data->img);
	new_image(data);
	return (0);
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	double		zoom;

	if (mousecode == 4 || mousecode == 5)
	{
		if (mousecode == 4)
			zoom = 1.20;
		else
			zoom = 0.80;
		data->ratio.re *= zoom;
		data->ratio.im *= zoom;
		data->centre.re = x - ((x - data->centre.re) * (1.0 / zoom));
		data->centre.im = y + ((data->centre.im - y) * (1.0 / zoom));
	}
	mlx_destroy_image(data->mlx, data->img);
	new_image(data);
	return (0);
}

//int		julia_motion(int x, int y, t_fractol *data)
//{
//	data->k.re = (x - data->centre.re) * data->ratio.re;
//	data->k.im = (data->centre.im - y) * data->ratio.im;
//	put_pxl_to_img(data, data->x, data->y, 0x0000FF);
//	return (1);
//}
