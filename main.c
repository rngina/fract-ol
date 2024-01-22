/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:05 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/22 17:00:42 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp("mandelbrot", argv[1], 10))
	{
		fractal.title = argv[1];
		init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	if (argc == 4 && !ft_strncmp("julia", argv[1], 5))
	{
		fractal.julia_x = ft_atof(argv[2]);
		fractal.julia_y = ft_atof(argv[3]);
		fractal.title = argv[1];
		init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 0);
		exit(1);
	}
}
