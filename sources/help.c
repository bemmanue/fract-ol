/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:14 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/11 18:50:16 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help(t_fractol *data)
{
	mlx_string_put(data->mlx, data->win, 231, 100, 0x00FFFFFF, "HELP");
	mlx_string_put(data->mlx, data->win, 95, 170, 0x00FFFFFF,
		" Change color  -  SPACEBAR");
	mlx_string_put(data->mlx, data->win, 95, 200, 0x00FFFFFF,
		"         Move  -  < >");
	mlx_string_put(data->mlx, data->win, 95, 230, 0x00FFFFFF,
		"         Zoom  -  SCROLL");
	mlx_string_put(data->mlx, data->win, 95, 260, 0x00FFFFFF,
		"   Iterations  -  +/-");
	mlx_string_put(data->mlx, data->win, 95, 290, 0x00FFFFFF,
		"        Reset  -  R");
	mlx_string_put(data->mlx, data->win, 95, 320, 0x00FFFFFF,
		"         Exit  -  ESCAPE");
	mlx_string_put(data->mlx, data->win, 95, 350, 0x00FFFFFF,
		"Julia setting  -  J");
}

void	print_help(void)
{
	ft_putstr_fd("Choose one of these fractals:\n", 1);
	ft_putstr_fd("* Mandelbrot\n", 1);
	ft_putstr_fd("* Julia\n", 1);
	ft_putstr_fd("* Burningship\n", 1);
	exit (0);
}
