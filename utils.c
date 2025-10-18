/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:20:59 by emkir             #+#    #+#             */
/*   Updated: 2025/10/18 14:21:02 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

double	atodbl(char *s)
{
	long	first_part;
	double	second_part;
	double	pow;
	int		sign;

	first_part = 0;
	second_part = 0;
	sign = +1;
	pow = 0.1;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		first_part = (first_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		second_part = second_part + (*s++ - 48) * pow;
		pow /= 10;
	}
	return ((first_part + second_part) * sign);
}
