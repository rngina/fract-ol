/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:20 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/23 12:32:19 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *arr)
{
	long integer_part;
	double fractional_part;
	double pow;
	int sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*arr >= 9 && *arr <= 13) || 32 == *arr)
		++arr;
	while ('+' == *arr || '-' == *arr)
		if ('-' == *arr++)
			sign = -sign;
	while (*arr != '.' && *arr)
		integer_part = (integer_part * 10) + (*arr++ - 48);
	if ('.' == *arr)
		++arr;
	while (*arr)
	{
		pow /= 10;
		fractional_part = fractional_part + (*arr++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}