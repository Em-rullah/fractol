/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:23 by emkir             #+#    #+#             */
/*   Updated: 2025/11/03 09:35:10 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(int z, int i, t_fractal *fractal, int color)
{
	int	offset;

	offset = (i * fractal->line_len) + (z * (fractal->bpp / 8));
	*(unsigned int *)(fractal->pixels_ptr + offset) = color;
}

static void	assign(t_fractal *fractal, int z, int i)
{
	if (!fractal->is_julia)
	{
		fractal->c_one.z = 0;
		fractal->c_one.i = 0;
		fractal->c_two.z = (((double)z / (double)SIZE) * 4.0 - 2.0)
			* fractal->zoom + fractal->move_z;
		fractal->c_two.i = (((double)i / (double)SIZE) * -4.0 + 2.0)
			* fractal->zoom + fractal->move_i;
	}
	else
	{
		fractal->c_one.z = (((double)z / (double)SIZE) * 4.0 - 2.0)
			* fractal->zoom + fractal->move_z;
		fractal->c_one.i = (((double)i / (double)SIZE) * -4.0 + 2.0)
			* fractal->zoom + fractal->move_i;
	}
}

static void	clean_placeholders(t_fractal *fractal)
{
	fractal->c_one.z = 0;
	fractal->c_one.i = 0;
	if (fractal->is_julia)
		return ;
	fractal->c_two.z = 0;
	fractal->c_two.i = 0;
}

static void	handle_pixel(int z, int i, t_fractal *fractal)
{
	int			count;

	count = 0;
	assign(fractal, z, i);
	while (count < ITERATIONS)
	{
		fractal->c_one = sum(square(fractal->c_one), fractal->c_two);
		if ((fractal->c_one.z * fractal->c_one.z)
			+ (fractal->c_one.i * fractal->c_one.i) > FRACTOL_ESCAPE)
		{
			pixel_put(z, i, fractal, (INF_COLOR * count));
			return ;
		}
		count++;
	}
	pixel_put(z, i, fractal, IN_RANGE_COLOR);
}

void	render(t_fractal *fractal)
{
	int			z;
	int			i;

	i = 0;
	if (fractal->is_julia)
	{
		fractal->c_two.z = fractal->julia_z;
		fractal->c_two.i = fractal->julia_i;
	}
	while (i < SIZE)
	{
		z = 0;
		while (z < SIZE)
		{
			handle_pixel(z, i, fractal);
			clean_placeholders(fractal);
			z++;
		}
		i++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img_ptr, 0, 0);
}
