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

void	new_image(t_fractol *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		terminate();
	data->addr = mlx_get_data_addr(data->img,
								   &data->bpp, &data->sl, &data->end);
	if (!data->addr)
		terminate();
	draw_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (!data->help)
		mlx_string_put(data->mlx, data->win, 380, 450, 0x00FFFFFF, "H - HELP");
	else
		show_help(data);
}

void	start_fractol(t_fractol *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		terminate();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->win)
		terminate();
	new_image(data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 6, 0, julia_motion, data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	*data;

	if (argc == 2)
	{
		data = init_fractol(argv[1]);
		if (!data)
			terminate();
		start_fractol(data);
	}
	else
		print_help();
	return (0);
}
