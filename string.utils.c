
#include "fractol.h"

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
