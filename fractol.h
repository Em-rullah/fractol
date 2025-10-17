
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 600
# define HEIGHT 600
# define ERR_MSG "Available options \"mandelbrot\" \"julia p_1 p_2\"\n"

# define ESC_KEY      65307
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
# define FRACTOL_COLOR	0xFF3300

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
}	t_fractal;

void		init(t_fractal *fractal);
void		render(t_fractal *fractal);
t_complex	sum(t_complex z1, t_complex z2);
t_complex	square(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
double		atodbl(char *s);
void		error_exit(void);
void		clean_window(t_fractal *fractal);
void		clean_image(t_fractal *fractal);
void		clean_pixels(t_fractal *fractal);
#endif