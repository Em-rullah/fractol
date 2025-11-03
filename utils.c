/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:20:59 by emkir             #+#    #+#             */
/*   Updated: 2025/11/03 09:35:56 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_complex	sum(t_complex c_one, t_complex c_two)
{
	t_complex	sum;

	sum.z = c_one.z + c_two.z;
	sum.i = c_one.i + c_two.i;
	return (sum);
}

t_complex	square(t_complex c)
{
	t_complex	square;

	square.z = (c.z * c.z) - (c.i * c.i);
	square.i = 2 * c.z * c.i;
	return (square);
}

static double	handle_point_decimal(char *s)
{
	double	result;
	double	denom;
	int		counter;

	result = 0;
	denom = 1;
	counter = 5;
	while (*s && (*s >= '0' && *s <= '9') && counter)
	{
		result = (result * 10) + (*s++ - 48);
		denom *= 10;
		counter--;
	}
	if (*s && !(*s >= '0' && *s <= '9'))
		error_exit(VALUE_ERROR);
	return (result / denom);
}

double	handle_point(char *s)
{
	double	part_one;
	double	part_two;
	int		sign;

	part_one = 0;
	part_two = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	part_one = ft_atoi(s);
	while (*s && *s >= '0' && *s <= '9')
		s++;
	if (!*s)
		return (part_one * sign);
	if (*s != '.')
		error_exit(VALUE_ERROR);
	part_two = handle_point_decimal(++s);
	return ((part_one + part_two) * sign);
}
