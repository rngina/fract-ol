/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:05 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/26 17:30:34 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_man(char **argv, t_fractal *fractal)
{
	fractal->title = argv[1];
	init_man(fractal);
	render_man(fractal);
	mlx_loop(fractal->mlx);
}

void	start_ship(char **argv, t_fractal *fractal)
{
	fractal->title = argv[1];
	init_ship(fractal);
	render_ship(fractal);
	mlx_loop(fractal->mlx);
}

void	start_julia(char **argv, t_fractal *fractal)
{
	fractal->cx = ft_atold(argv[2]);
	fractal->cy = ft_atold(argv[3]);
	fractal->title = argv[1];
	init_julia(fractal);
	render_julia(fractal);
	mlx_loop(fractal->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strcmp("mandelbrot", argv[1]))
		start_man(argv, &fractal);
	if (argc == 2 && !ft_strcmp("ship", argv[1]))
		start_ship(argv, &fractal);
	if (argc == 4 && !ft_strcmp("julia", argv[1]))
		start_julia(argv, &fractal);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 0);
		exit(1);
	}
}
