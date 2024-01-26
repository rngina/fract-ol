/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:20 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/26 16:56:22 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *arr)
{
	int		integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
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

int	check_numerics(char *arr)
{
	int	dot;

	dot = 0;
	if (*arr == '-' || *arr == '+')
		arr++;
	while (*arr)
	{
		if ((*arr >= '0' && *arr <= '9' ) || *arr == '.')
		{
			if (*arr == '.')
			{
				if (dot == 0)
					dot++;
				else
					return (0);
			}
		}
		else
			return (0);
		arr++;
	}
	return (1);
}

double	ft_atold(char *arr)
{
	double	num;
	int		check;

	check = check_numerics(arr);
	if (check == 0)
		numeric_error();
	num = ft_atof(arr);
	return (num);
}
