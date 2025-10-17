
#include "fractol.h"


static void	pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	if (!fractal->is_julia)
	{
		z.x = 0;
		z.y = 0;
		c.x = ((x / (double)WIDTH) * 4.0 - 2.0)
			* fractal->zoom + fractal->move_x;
		c.y = ((y / (double)HEIGHT) * -4.0 + 2.0)
			* fractal->zoom + fractal->move_y;
	}
	else
	{
		z.x = ((x / (double)WIDTH) * 4.0 - 2.0)
			* fractal->zoom + fractal->move_x;
		z.y = ((y / (double)HEIGHT) * -4.0 + 2.0)
			* fractal->zoom + fractal->move_y;
		c.x = fractal->julia_x;
		c.y = fractal->julia_y;
	}
	while (i < ITERATIONS)
	{
		z = sum(square(z), c);
		if ((z.x * z.x)
			+ (z.y * z.y) > FRACTOL_ESCAPE)
		{
			pixel_put(x, y, fractal, (INF_COLOR * i));
			return ;
		}
		i++;
	}
	pixel_put(x, y, fractal, FRACTOL_COLOR);
}

void	render(t_fractal *fractal)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img_ptr, 0, 0);
}
