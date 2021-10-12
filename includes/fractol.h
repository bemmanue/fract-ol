/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:57:03 by bemmanue          #+#    #+#             */
/*   Updated: 2021/09/11 18:57:05 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"

# define WIDTH 500
# define HEIGHT	500
# define MAX_ITERATION 32

# define SPACEBAR 49
# define ESCAPE 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_J 38
# define KEY_H 4
# define KEY_R 15
# define PLUS 69
# define MINUS 78

typedef struct s_color
{
	double			red;
	double			blue;
	double			green;
}					t_color;

typedef struct s_comp
{
	double			re;
	double			im;
}					t_comp;

typedef struct s_fractol
{
	char		*name;
	void		(*calculate)(struct s_fractol *data);
	int			(*julia_motion)(int x, int y, struct s_fractol *data);
	int			fixed_julia;
	int			help;
	t_comp		max;
	t_comp		min;
	t_comp		ratio;
	t_comp		centre;
	t_comp		z;
	t_comp		c;
	t_comp		k;
	t_color		color;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			end;
	int			sl;
	int			bpp;
	int			x;
	int			y;
	int			colorstep;
	int			colormode;
	int			iteration;
	int			max_iteration;
}				t_fractol;

t_fractol	*init_fractol(char *name);
t_fractol	*fill_data(char *name, void (*f)(t_fractol *));
int			check_name(const char *s1, const char *s2);
void		start_fractol(t_fractol *data);
void		new_image(t_fractol *data);
void		draw_image(t_fractol *data);
void		pixel_put(t_fractol *data, int x, int y, int color);
t_comp		init_complex(double re, double im);
int			calculate_color(t_fractol *data);
void		calculate_colorstep(t_fractol *data);
void		reset_fractol(t_fractol *data);
int			key_hook(int keycode, t_fractol *data);
int			mouse_hook(int mousecode, int x, int y, t_fractol *data);
int			julia_motion(int x, int y, t_fractol *data);

void		mandelbrot(t_fractol *data);
void		julia(t_fractol *data);
void		burningship(t_fractol *data);

void		print_help(void);
void		show_help(t_fractol *data);
void		terminate(void);

#endif
