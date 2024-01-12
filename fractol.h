/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:33 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/12 14:44:11 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define ERROR_MESSAGE "Please enter one of the \
following:\n\t\"./fractol mandelbrot\"\n\t\"./fractol \
julia <value 1> <value 2>\"\n"

typedef struct	s_complex
{
	double	real;
	double	i;
} 			t_complex;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct	s_fractal
{
	char		*fract_type;
	void		*mlx;
	void		*mlx_win;
	t_image		*img;
}			t_fractal;

int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);

#endif
