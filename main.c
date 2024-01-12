/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:05 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/11 17:28:47 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    if ((argc == 2 && !ft_strncmp("mandelbrot", argv[1], 10)) || \
        (argc == 4 && !ft_strncmp("julia", argv[1], 5)))
    {
        exit (0);
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, 0);
        exit (1);
    }
}
