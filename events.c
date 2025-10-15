
#include "fractol.h"


int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}


int	key_handler(int notation, t_fractal *fractal)
{
	printf("%i\n", notation);
	if (notation == 65307)
		close_handler(fractal);
	else if (notation == 52)
		fractal->iterations_definition += 10;
	else if (notation == 45)
		fractal->iterations_definition -= 10;

	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
    (void)y;
	if (button == 4)
		fractal->zoom *= 0.95;
	else if (button == 5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
