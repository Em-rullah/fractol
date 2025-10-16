
#include "fractol.h"

static void	error_exit(t_fractal *fractal)
{
	free(fractal);
	ft_putstr_fd("Problem with initialization\n", 2);
	exit(EXIT_FAILURE);
}

void	clean_init(t_fractal *fractal)
{
	error_exit(fractal);
}

void	clean_window(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	error_exit(fractal);
}

void	clean_image(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	clean_window(fractal);
}