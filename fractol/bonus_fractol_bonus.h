/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractol_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:13:59 by federico          #+#    #+#             */
/*   Updated: 2025/07/12 02:48:59 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_FRACTOL_BONUS_H
# define BONUS_FRACTOL_BONUS_H

# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define FRACTAL_ITERATIONS 128
# define ESCAPE_VALUE 4
# define OLD_MIN 0
# define MLX_DEFAULT 0
# define FAILURE 0
# define SUCCESS 1
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define FRACTAL_COLOR 0x00FFFFFF

typedef struct s_fractal_parameters
{
	char	*name;
	double	zoom_state;
	double	shift_x;
	double	shift_y;
	int		fractal_iterations;
	double	julia_x;
	double	julia_y;
}				t_fractal_parameters;

typedef struct s_mlx_data
{
	void					*instance;
	void					*window;
	void					*image;
	char					*bit_address;
	int						bpp;
	int						line_len;
	int						endian;
	t_fractal_parameters	parameters;
}				t_mlx_data;

typedef struct s_complex
{
	double	x;
	double	yi;
}				t_complex;

int			put_char(char c);
void		explain_fractol(void);
void		put_string(char *str);
int			strings_are_equal(char *str1, char *str2);
void		mandelbrot(char *name);
void		initialize_mlx(t_mlx_data *data, char *name);
int			close_everything(t_mlx_data *data);
void		put_pixel(t_mlx_data *data, int x, int y, int color);
double		scale(double unscaled, double old_max,
				double new_min, double new_max);
double		squared_hypotenuse(t_complex z);
t_complex	sum_complex(t_complex c, t_complex z);
t_complex	square_complex(t_complex z);
void		render_mandelbrot(t_mlx_data *data);
void		pixel_by_pixel_mandelbrot(int x, int y, t_mlx_data *data);
void		hook_handlers(t_mlx_data *data);
void		initialize_parameters_mandelbrot(t_mlx_data *data, char *name);
int			key_press_handling(int keysym, t_mlx_data *data);
int			mouse_handling(int button, int x, int y, t_mlx_data *data);
void		julia(char	*name, double julia_x, double julia_y);
void		initialize_parameters_julia(t_mlx_data *data,
				char *name, double julia_x, double julia_y);
void		render_julia(t_mlx_data *data);
void		pixel_by_pixel_julia(int x, int y, t_mlx_data *data);
int			real_number(char *str);
double		convert_string_to_double(char *str);
int			visibility_handling(t_mlx_data *data);
void		malloc_error(char position);
void		burning_ship(char *name);
void		render_ship(t_mlx_data *data);
t_complex	square_complex_ship(t_complex z);
void		pixel_by_pixel_ship(int x, int y, t_mlx_data *data);
void		render_fractal(t_mlx_data *data);
int			key_press_ship(int keysym, t_mlx_data *data);

#endif