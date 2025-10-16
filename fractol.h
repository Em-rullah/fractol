
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
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
# define ITERATIONS 420
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

	t_complex	z;
	t_complex	c;
	int			max_i;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}	t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
double		atodbl(char *s);
void		clean_init(t_fractal *fractal);
void		clean_window(t_fractal *fractal);
void		clean_image(t_fractal *fractal);
void		clean_pixels(t_fractal *fractal);
#endif