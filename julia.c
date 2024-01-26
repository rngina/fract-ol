/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:54:41 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/26 17:45:32 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	set_z_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;

	z.real = scale_range(x, fractal->limit.min_x, fractal->limit.max_x, \
	WIDTH) + fractal->shift_x;
	z.im = scale_range(y, fractal->limit.min_y, fractal->limit.max_y, \
	HEIGHT) + fractal->shift_y;
	return (z);
}

void	check_pixel_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z = set_z_julia(x, y, fractal);
	c.real = fractal->cx;
	c.im = fractal->cy;
	i = 0;
	while (i < fractal->iterations)
	{
		z = sum_z(mult_z(z, z), c);
		if ((z.real * z.real) + (z.im * z.im) > fractal->escape)
		{
			color = scale_range(i, CYAN, WHITE, fractal->iterations);
			put_pixel(x, y, &(fractal->img), color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &(fractal->img), WHITE);
}

void	render_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			check_pixel_julia(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, \
	fractal->img.img, 0, 0);
}
