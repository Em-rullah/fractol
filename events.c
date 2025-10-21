/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:04 by emkir             #+#    #+#             */
/*   Updated: 2025/10/21 23:32:46 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int notation, t_fractal *fractal)
{
	(void)notation;
	if (notation == ESC_KEY)
		close_handler(fractal);
	else if (notation == ARROW_UP)
		fractal->move_y += (0.5 * fractal->zoom);
	else if (notation == ARROW_DOWN)
		fractal->move_y -= (0.5 * fractal->zoom);
	else if (notation == ARROW_RIGHT)
		fractal->move_x += (0.5 * fractal->zoom);
	else if (notation == ARROW_LEFT)
		fractal->move_x -= (0.5 * fractal->zoom);
	render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		fractal->zoom *= 0.5;
	else if (button == SCROLL_DOWN)
		fractal->zoom *= 1.5;
	render(fractal);
	return (0);
}
