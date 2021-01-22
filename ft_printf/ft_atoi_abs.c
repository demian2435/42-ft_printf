#include "ft_printf.h"

int ft_atoi_abs(const char *nptr)
{
	long int sum;

	sum = 0;
	while (ft_isdigit(*nptr))
	{
		sum *= 10;
		sum += *nptr++ - '0';
		if (sum < 0)
			return (-1);
	}
	return (sum);
}