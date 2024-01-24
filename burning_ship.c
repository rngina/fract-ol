/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:50:31 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/24 16:38:36 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_pixel_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	double		temp;

	z.real = scale_range(x, fractal->limit.min_x, fractal->limit.max_x, 0, WIDTH) + fractal->shift_x;
	z.im = scale_range(y, fractal->limit.min_y, fractal->limit.max_y, 0, HEIGHT) + fractal->shift_y;
	c.real = z.real;
	c.im = z.im;
	i = 0;
	while (i < fractal->iterations)
	{
		temp = z.real*z.real - z.im*z.im + c.real;
		z.im = 2 * fabs(z.real * z.im) + c.im;
		z.real = temp;
		if ((z.real * z.real) + (z.im * z.im) > fractal->escape)
		{
			color = scale_range(i, CYAN, WHITE, 0, fractal->iterations);
			put_pixel(x, y, &(fractal->img), color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &(fractal->img), WHITE);
}

void	render_ship(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			check_pixel_ship(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img, 0,
			0);
}