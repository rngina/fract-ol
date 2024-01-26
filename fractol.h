/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:27:33 by rtavabil          #+#    #+#             */
/*   Updated: 2024/01/26 17:48:21 by rtavabil         ###   ########.fr       */
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
# include <float.h>
# include <limits.h>

# define ERROR_MESSAGE "Please enter one of the \
following:\n\t\"./fractol mandelbrot\"\n\t\"./fractol \
julia <double value 1> <double value 2>\"\n\t\"./fractol \
ship\"\n"

# define NUM_ERROR "Please enter numeric parameters"

# define WIDTH 800
# define HEIGHT 800

# define ESCAPE 4
# define ITERATIONS 100

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
# define PeachPuff2 0xeecbad

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


typedef struct s_limit
{
		double	max_x;
		double	min_x;
		double	max_y;
		double	min_y;
}				t_limit;

typedef struct s_fractal
{
	char	*title;
	void	*mlx;
	void	*mlx_win;
	t_image	img;
	int		escape;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	cx;
	double	cy;
	t_limit	limit;
}			t_fractal;

int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
void		init_error(void);
void		numeric_error(void);


t_complex	sum_z(t_complex z1, t_complex z2);
t_complex	mult_z(t_complex z1, t_complex z2);

double		ft_atold(char *arr);

double		map_x(int x, t_fractal *fractal);
double		map_y(int y, t_fractal *fractal);
void		set_zoom(double zoom, int x, int y, t_fractal *fractal);
double		scale_range(double num, double new_min, double new_max,
		double old_max);

int			handle_close_x(t_fractal *fractal);

//mandelbrot
void		init_man(t_fractal *fractal);
void		render_man(t_fractal *fractal);

//julia
void		init_julia(t_fractal *fractal);
void		render_julia(t_fractal *fractal);

//burning ship
void		init_ship(t_fractal *fractal);
void		render_ship(t_fractal *fractal);

//rendering
void		put_pixel(int x, int y, t_image *image, int color);

//initialization
void		set_values(t_fractal *fractal);

#endif
