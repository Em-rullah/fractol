
#include "fractol.h"

void	error_exit(void)
{
	ft_putstr_fd("Problem with initialization\n", 2);
	exit(EXIT_FAILURE);
}

void	clean_window(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	error_exit();
}

void	clean_image(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	clean_window(fractal);
}
