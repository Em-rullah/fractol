/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:46:45 by emkir             #+#    #+#             */
/*   Updated: 2025/10/21 23:32:45 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_window(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	error_exit(MLX_ERROR);
}

void	clean_image(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	clean_window(fractal);
}
