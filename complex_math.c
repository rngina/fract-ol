/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:24:05 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/23 13:34:01 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_z(t_complex z1, t_complex z2)
{
	t_complex	ret;

	ret.real = z1.real + z2.real;
	ret.im = z1.im + z2.im;
	return (ret);
}

t_complex	mult_z(t_complex z1, t_complex z2)
{
	t_complex	ret;

	ret.real = z1.real * z1.real - z2.im * z2.im;
	ret.im = 2 * z1.real * z2.im;
	return (ret);
}

double	abs_z(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_complex	ship_z(t_complex z, t_complex c)
{
	t_complex	ret;

	ret.real = z.real * z.real - z.im * z.im + c.real;
	ret.im = 2 * abs_z(z.real * z.im) + c.im;
	return (ret);
}
