#include "ft_printf.h"

int ft_isterminator(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return 1;
	else
		return 0;
}