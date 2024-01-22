/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:54:41 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/22 16:39:10 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_range(double num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min)
		+ new_min);
}

void	put_pixel(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_length) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->addr + offset) = color;
}

void	check_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = 0.0;
	z.im = 0.0;
	if (fractal->title == "julia")
	{
		c.real = (scale_range(x, -2, 2, 0, WIDTH) + fractal->shift_x)
			* fractal->zoom;
		c.im = (scale_range(y, 2, -2, 0, HEIGHT) + fractal->shift_y)
			* fractal->zoom;
	}
	else
	{
		c.real = (scale_range(x, -2, 2, 0, WIDTH) + fractal->shift_x)
			* fractal->zoom;
		c.im = (scale_range(y, 2, -2, 0, HEIGHT) + fractal->shift_y)
			* fractal->zoom;
	}
	i = 0;
	while (i < fractal->iterations)
	{
		z = sum_z(mult_z(z, z), c);
		if ((z.real * z.real) + (z.im * z.im) > fractal->escape)
		{
			color = scale_range(i, BLACK, WHITE, 0, fractal->iterations);
			put_pixel(x, y, &(fractal->img), color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &(fractal->img), MAGENTA);
}

void	render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			check_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img, 0,
			0);
}