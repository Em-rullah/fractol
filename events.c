
#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	free(fractal);
	exit(EXIT_SUCCESS);
}


int	key_handler(int notation, t_fractal *fractal)
{
	(void)notation;
	if (notation == ESC_KEY)
		close_handler(fractal);
	else if (notation == ARROW_UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (notation == ARROW_DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (notation == ARROW_RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (notation == ARROW_LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		fractal->zoom *= 0.95;
	else if (button == SCROLL_DOWN)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
