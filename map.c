/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:42:05 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/24 14:50:40 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_x(int x, t_fractal *fractal)
{
	double	range;
	double	ret;

	range = (fractal->limit.max_x - fractal->limit.min_x) / WIDTH;
	ret = x * range + fractal->limit.min_x;
	return (ret);
}

double	map_y(int y, t_fractal *fractal)
{
	double	range;
	double	ret;

	range = (fractal->limit.max_y - fractal->limit.min_y) / HEIGHT;
	ret = y * range + fractal->limit.min_y;
	return (ret);
}

void	set_zoom(double zoom, int x, int y, t_fractal *fractal)
{
	double	beta_x;
	double	beta_y;

	beta_x = map_x(x, fractal);
	beta_y = map_y(y, fractal);
	fractal->limit.max_x = fractal->limit.max_x * zoom + beta_x * (1 - zoom);
	fractal->limit.min_x = fractal->limit.min_x * zoom + beta_x * (1 - zoom);
	fractal->limit.max_y = fractal->limit.max_y * zoom + beta_y * (1 - zoom);
	fractal->limit.min_y = fractal->limit.min_y * zoom + beta_y * (1 - zoom);
}

double	scale_range(double num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min)
		+ new_min);
}