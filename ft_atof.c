/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:20 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/22 15:57:18 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *arr)
{
	int i;
	int j;
	double val;

	i = 0;
	j = 0;
	val = 0;
	while (*(arr + i) != '\0' && *(arr + i) >= '0' && *(arr + i) <= '9')
	{
		val = (val * 10) + (*(arr + i) - '0');
		i++;
	}
	if (*(arr + i) == '.')
		i++;
	while (*(arr + i) != '\0' && *(arr + i) >= '0' && *(arr + i) <= '9')
	{
		val = (val * 10) + (*(arr + i) - '0');
		i++;
		j--;
	}
	val = val * pow(10, j);
	return (val);
}