
#include "fractol.h"

double	*calculate_colorstep(t_fractol *data, int t, int r, int g, int b)
{
	double	*step;

	step = malloc(sizeof(double) * 4);
	step[0] = (double) t / data->max_iteration;
	step[1] = (double) r / data->max_iteration;
	step[2] = (double) g / data->max_iteration;
	step[3] = (double) b / data->max_iteration;
	return (step);
}

void	calculate_color(t_fractol *data)
{
	double   		*colorstep;
	int             i;
	unsigned char	color[4];

	if (data->colormode % 3 == 0)
		colorstep = calculate_colorstep(data, 0x00, 0xFF, 0x66, 0x99);
	else if (data->colormode % 3 == 1)
		colorstep = calculate_colorstep(data, 0x00, 0x99, 0xFF, 0x66);
	else
		colorstep = calculate_colorstep(data,0x00, 0x66, 0x99, 0xFF);
	i = 0;
	while (i < 4)
	{
		data->color <<= 8;
		color[i] = *colorstep * data->iteration;
		data->color += color[i];
		colorstep++;
		i++;
	}
}