/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:16 by emkir             #+#    #+#             */
/*   Updated: 2025/11/03 09:18:38 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data(t_fractal *fractal)
{
	fractal->move_z = 0.0;
	fractal->move_i = 0.0;
	fractal->zoom = 1.0;
}

static void	fractal_start(t_fractal *fractal)
{
	data(fractal);
	init(fractal);
	render(fractal);
	mlx_loop(fractal->mlx_connection);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (av[1] == NULL)
		error_exit(MAIN_ARG_ERROR);
	else if (!ft_strncmp(av[1], "mandelbrot", 10) && 2 == ac)
	{
		fractal.name = av[1];
		fractal.is_julia = 0;
		fractal_start(&fractal);
	}
	else if (!ft_strncmp(av[1], "julia", 5) && ac != 4)
		error_exit(VALUE_ERROR);
	else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
	{
		fractal.julia_z = handle_point(av[2]);
		fractal.julia_i = handle_point(av[3]);
		if (fractal.julia_z < -10.0 || fractal.julia_z > 10.0
			|| fractal.julia_i < -10.0 || fractal.julia_i > 10.0)
			error_exit("Julia values must be between -10.0 and 10.0\n");
		fractal.name = av[1];
		fractal.is_julia = 1;
		fractal_start(&fractal);
	}
	else
		error_exit(MAIN_ARG_ERROR);
}
