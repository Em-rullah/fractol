
#include "fractol.h"


static void	pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->pixels_ptr + offset) = color;
}

static void	check_julia(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->z.x = ((x / (double)WIDTH) * 4.0 - 2.0)
			* fractal->zoom + fractal->shift_x;
		fractal->z.y = ((y / (double)HEIGHT) * -4.0 + 2.0)
			* fractal->zoom + fractal->shift_y;
		fractal->c.x = fractal->julia_x;
		fractal->c.y = fractal->julia_y;
	}
	else
	{
		fractal->z.x = 0.0;
		fractal->z.y = 0.0;
		fractal->c.x = ((x / (double)WIDTH) * 4.0 - 2.0)
			* fractal->zoom + fractal->shift_x;
		fractal->c.y = ((y / (double)HEIGHT) * -4.0 + 2.0)
			* fractal->zoom + fractal->shift_y;
	}

}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	unsigned int	i;

	i = 0;
	check_julia(x, y, fractal);
	while (i < ITERATIONS)
	{
		fractal->z = sum_complex(square_complex(fractal->z), fractal->c);
		if ((fractal->z.x * fractal->z.x)
			+ (fractal->z.y * fractal->z.y) > FRACTOL_ESCAPE)
		{
			pixel_put(x, y, fractal, (INF_COLOR * i) & 0xFFFFFF);
			return ;
		}
		i++;
	}
	pixel_put(x, y, fractal, FRACTOL_COLOR);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

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
