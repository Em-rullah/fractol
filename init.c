/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:47:14 by emkir             #+#    #+#             */
/*   Updated: 2025/10/20 10:31:17 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		error_exit(MLX_ERROR);
	fractal->mlx_window = (void *)mlx_new_window(fractal->mlx_connection,
			SIZE, SIZE, fractal->name);
	if (fractal->mlx_window == NULL)
		clean_window(fractal);
	fractal->img_ptr = mlx_new_image(fractal->mlx_connection,
			SIZE, SIZE);
	if (fractal->img_ptr == NULL)
		clean_image(fractal);
	fractal->pixels_ptr = mlx_get_data_addr(fractal->img_ptr,
			&fractal->bpp,
			&fractal->line_len, &fractal->endian);
	if (fractal->pixels_ptr == NULL)
		clean_image(fractal);
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, 1L << 17, close_handler, fractal);
}
