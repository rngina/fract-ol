/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:36:58 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/18 13:52:16 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close_esc(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit(1);
	}
	return (0);
}

int	handle_close_x(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(1);
}

void	set_values(t_fractal *fractal)
{
	fractal->escape = ESCAPE;
	fractal->iterations = ITERATIONS;
}

void	init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		free_error();
	printf("mlx init\n");
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->title);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		free_error();
	}
	printf("mlx_win init\n");
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		free_error();
	}
	printf("img init\n");
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
											&(fractal->img.bits_per_pixel),
											&(fractal->img.line_length),
											&(fractal->img.endian));
	printf("img_addr init\n");
	set_values(fractal);
	mlx_key_hook(fractal->mlx_win, handle_close_esc, fractal);
	mlx_hook(fractal->mlx_win,
				DestroyNotify,
				StructureNotifyMask,
				handle_close_x,
				fractal);
}