/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:20:59 by emkir             #+#    #+#             */
/*   Updated: 2025/10/20 10:46:09 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

t_complex	square(t_complex z)
{
	t_complex	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * z.x * z.y;
	return (square);
}

double	handle_point(char *s)
{
	double	part_one;
	double	part_two;
	double	sign;
	double	pow;
	int		count;

	part_one = 0;
	part_two = 0;
	pow = 0.1;
	count = 4;
	sign = 1;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s && *s >= '0' && *s <= '9')
		part_one = (part_one * 10) + (*s++ - 48);
	if (!*s)
		return (part_one * sign);
	if (*s != '.')
		error_exit(VALUE_ERROR);
	s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		if (!count)
			return ((part_one + part_two) * sign);
		part_two = part_two + (*s++ - 48) * pow;
		pow /= 10;
		count--;
	}
	return ((part_one + part_two) * sign);
}
