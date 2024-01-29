/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:55:47 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/29 17:00:08 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_error(void)
{
	ft_putstr_fd("Something went wrong\n", 2);
	exit(1);
}

void	numeric_error(void)
{
	ft_putstr_fd(NUM_ERROR, 2);
	exit(1);
}
