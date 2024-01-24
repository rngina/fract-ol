/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:54:41 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/24 16:44:53 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_length) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->addr + offset) = color;
}

void	check_pixel_man(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = scale_range(x, fractal->limit.min_x, fractal->limit.max_x, 0, WIDTH) + fractal->shift_x;
	z.im = scale_range(y, fractal->limit.min_y, fractal->limit.max_y, 0, HEIGHT) + fractal->shift_y;
	c.real = z.real;
	c.im = z.im;
	i = 0;
	while (i < fractal->iterations)
	{
		z = sum_z(mult_z(z, z), c);
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

void	render_man(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			check_pixel_man(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img, 0,
			0);
}