/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:14:06 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/04 11:14:09 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	new_image(t_fractol *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->sl, &data->end);
	draw_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	start_fractol(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	new_image(data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	//	mlx_hook(data->win, 6, 0, julia_motion, data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_loop(data->mlx);
}

int		main(int argc, char **argv)
{
	t_fractol	*data;

	if (argc == 2)
	{
		data = init_fractol(argv[1]);
		if (!data)
			print_help();
		else
			start_fractol(data);
	}
	else
		print_help();
	return (0);
}
