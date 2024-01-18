/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:24:05 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/18 13:45:05 by rtavabil         ###   ########.fr       */
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
