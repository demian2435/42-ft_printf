#include "ft_printf.h"

int ft_putlstr(char *s, int len)
{
	int count;

	count = 0;
	if (len == -1)
	{
		while (*s)
			count += ft_putlchar(*s++);
	}
	else
	{
		while (*s && len)
		{
			count += ft_putlchar(*s++);
			len--;
		}
	}
	return (count);
}