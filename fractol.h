/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:12 by emkir             #+#    #+#             */
/*   Updated: 2025/10/25 13:54:42 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define SIZE 500
# define MAIN_ARG_ERROR "Available options: \"./fractol \
mandelbrot\" \"./fractol julia value\".\n"
# define MLX_ERROR "Cannot initialize window.\n"
# define VALUE_ERROR "Value must be formatted like this: reel imaginary. \
Examples: -0.8 0.156 , -0.7269 0.1889. \n"

# define ESC_KEY      65307
# define ARROW_UP     65362
# define ARROW_DOWN   65364
# define ARROW_LEFT   65361
# define ARROW_RIGHT  65363
# define SCROLL_UP    4
# define SCROLL_DOWN  5

# define FRACTOL_ESCAPE 4
# define ITERATIONS 42	

# define INF_COLOR 0xFCBE11
# define IN_RANGE_COLOR	0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;

	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;

	double		move_x;
	double		move_y;
	double		zoom;

	int			is_julia;
	double		julia_x;
	double		julia_y;
	t_complex	z;
	t_complex	c;
}	t_fractal;

void		init(t_fractal *fractal);
void		render(t_fractal *fractal);

int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

void		error_exit(char	*s);
void		clean_window(t_fractal *fractal);
void		clean_image(t_fractal *fractal);

double		handle_point(char *s);
t_complex	sum(t_complex z1, t_complex z2);
t_complex	square(t_complex z);
#endif