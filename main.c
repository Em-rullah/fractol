/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:16 by emkir             #+#    #+#             */
/*   Updated: 2025/10/19 12:04:48 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data(t_fractal *fractal)
{
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
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

	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		fractal.name = av[1];
		fractal.is_julia = 0;
		fractal_start(&fractal);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.julia_x = handle_point(av[2]);
		fractal.julia_y = handle_point(av[3]);
		fractal.name = av[1];
		fractal.is_julia = 1;
		fractal_start(&fractal);
	}
	else
	{
		error_exit(MAIN_ARG_ERROR);
	}
}
