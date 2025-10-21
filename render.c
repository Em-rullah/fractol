/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:23 by emkir             #+#    #+#             */
/*   Updated: 2025/10/21 23:32:54 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->pixels_ptr + offset) = color;
}

static void	assign(t_fractal *fractal, int x, int y)
{
	if (!fractal->is_julia)
	{
		fractal->z.x = 0;
		fractal->z.y = 0;
		fractal->c.x = (((double)x / (double)SIZE) * 4.0 - 2.0)
			* fractal->zoom + fractal->move_x;
		fractal->c.y = (((double)y / (double)SIZE) * -4.0 + 2.0)
			* fractal->zoom + fractal->move_y;
	}
	else
	{
		fractal->z.x = (((double)x / (double)SIZE) * 4.0 - 2.0)
			* fractal->zoom + fractal->move_x;
		fractal->z.y = (((double)y / (double)SIZE) * -4.0 + 2.0)
			* fractal->zoom + fractal->move_y;
	}
}

static void	clean_placeholders(t_fractal *fractal)
{
	fractal->z.x = 0;
	fractal->z.y = 0;
	if (fractal->is_julia)
		return ;
	fractal->c.x = 0;
	fractal->c.y = 0;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int			i;

	i = 0;
	assign(fractal, x, y);
	while (i < ITERATIONS)
	{
		fractal->z = sum(square(fractal->z), fractal->c);
		if ((fractal->z.x * fractal->z.x)
			+ (fractal->z.y * fractal->z.y) > FRACTOL_ESCAPE)
		{
			pixel_put(x, y, fractal, (INF_COLOR * i));
			return ;
		}
		i++;
	}
	pixel_put(x, y, fractal, IN_RANGE_COLOR);
}

void	render(t_fractal *fractal)
{
	int			x;
	int			y;

	y = 0;
	if (fractal->is_julia)
	{
		fractal->c.x = fractal->julia_x;
		fractal->c.y = fractal->julia_y;
	}
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			handle_pixel(x, y, fractal);
			clean_placeholders(fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img_ptr, 0, 0);
}
