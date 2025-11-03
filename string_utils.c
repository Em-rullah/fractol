/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:38:23 by emrul             #+#    #+#             */
/*   Updated: 2025/11/03 11:20:31 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*uns_s1;
	const unsigned char	*uns_s2;

	uns_s1 = (const unsigned char *)s1;
	uns_s2 = (const unsigned char *)s2;
	while (n && (*uns_s1 || *uns_s2))
	{
		if (*uns_s1 > *uns_s2)
			return (*uns_s1 - *uns_s2);
		else if (*uns_s1 < *uns_s2)
			return (*uns_s1 - *uns_s2);
		uns_s1++;
		uns_s2++;
		n--;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_atoi(char **nptr)
{
	long	n;

	n = 0;
	while ('0' <= **nptr && **nptr <= '9')
	{
		n = 10 * n + (**nptr - '0');
		(*nptr)++;
	}
	return (n);
}
