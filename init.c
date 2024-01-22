/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:36:58 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/22 14:38:47 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit(1);
	}
	if (keysym == XK_Up)
		fractal->shift_y -= 0.2;
	if (keysym == XK_Down)
		fractal->shift_y += 0.2;
	if (keysym == XK_Right)
		fractal->shift_x -= 0.2;
	if (keysym == XK_Left)
		fractal->shift_x += 0.2;
	render(fractal);
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

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
		fractal->zoom *= 1.1;
	else if (button == 5)
		fractal->zoom /= 1.1;
	render(fractal);
	return (x * y);
}

void	set_values(t_fractal *fractal)
{
	fractal->escape = ESCAPE;
	fractal->iterations = ITERATIONS;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
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
	mlx_mouse_hook(fractal->mlx_win, handle_mouse, fractal);
	mlx_key_hook(fractal->mlx_win, handle_key, fractal);
	mlx_hook(fractal->mlx_win,
				DestroyNotify,
				StructureNotifyMask,
				handle_close_x,
				fractal);
}