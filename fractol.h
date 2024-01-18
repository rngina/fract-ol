/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:33 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:35 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Please enter one of the \
following:\n\t\"./fractol mandelbrot\"\n\t\"./fractol \
julia <value 1> <value 2>\"\n"

# define WIDTH 800
# define HEIGHT 800

# define ESCAPE 2
# define ITERATIONS 20

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define MAGENTA 0xFF00FF
# define CYAN 0x00FFFF
# define GRAY 0x808080
# define LIGHT_GRAY 0xC0C0C0
# define DARK_GRAY 0x404040
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define BROWN 0xA52A2A
# define PINK 0xFFC0CB
# define LIME 0x00FF00

typedef struct s_complex
{
	double	real;
	double	im;
}			t_complex;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_fractal
{
	char	*title;
	void	*mlx;
	void	*mlx_win;
	t_image	img;
	int		escape;
	int		iterations;
}			t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
void		init(t_fractal *fractal);
void		free_error(void);

t_complex	sum_z(t_complex z1, t_complex z2);
t_complex	mult_z(t_complex z1, t_complex z2);

void		render(t_fractal *fractal);

#endif
