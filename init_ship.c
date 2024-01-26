/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:36:58 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/26 17:30:14 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_ship(int keysym, t_fractal *fractal)
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
		fractal->shift_y -= 0.2 * fractal->zoom;
	if (keysym == XK_Down)
		fractal->shift_y += 0.2 * fractal->zoom;
	if (keysym == XK_Right)
		fractal->shift_x -= 0.2 * fractal->zoom;
	if (keysym == XK_Left)
		fractal->shift_x += 0.2 * fractal->zoom;
	render_ship(fractal);
	return (0);
}

int	handle_mouse_ship(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		set_zoom(1.1, x, y, fractal);
	}
	else if (button == 5)
	{
		fractal->zoom /= 1.1;
		set_zoom(0.9, x, y, fractal);
	}
	render_ship(fractal);
	return (x * y);
}

void	set_values_ship(t_fractal *fractal)
{
	fractal->escape = ESCAPE;
	fractal->iterations = ITERATIONS;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->limit.max_x = 2;
	fractal->limit.min_x = -2;
	fractal->limit.max_y = 2;
	fractal->limit.min_y = -2;
}

void	init_events_ship(t_fractal *fractal)
{
	set_values_ship(fractal);
	mlx_mouse_hook(fractal->mlx_win, handle_mouse_ship, fractal);
	mlx_key_hook(fractal->mlx_win, handle_key_ship, fractal);
	mlx_hook(fractal->mlx_win, \
	DestroyNotify, \
	StructureNotifyMask, \
	handle_close_x, \
	fractal);
}

void	init_ship(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		init_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->title);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		init_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		init_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&(fractal->img.bits_per_pixel),
			&(fractal->img.line_length),
			&(fractal->img.endian));
	init_events_ship(fractal);
}
