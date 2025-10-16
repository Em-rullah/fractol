
#include "fractol.h"



static void	data(t_fractal *fractal)
{
	fractal->max_i = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	fractal_start(t_fractal *fractal)
{
	data(fractal);
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connection);
}

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		fractal->name = av[1];
		fractal_start(fractal);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal->name = av[1];
		fractal->julia_x = atodbl(av[2]);
		fractal->julia_y = atodbl(av[3]);
		fractal_start(fractal);
	}
	else
	{
		ft_putstr_fd(ERR_MSG, 2);
		exit(EXIT_FAILURE);
	}
}
