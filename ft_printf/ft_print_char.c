#include "ft_printf.h"

int ft_print_char(t_flags *flags, int c)
{
	int count;

	count = 0;
	if (flags->minus)
	{
		count += ft_putlchar(c);
		while (flags->size > 1)
		{
			count += ft_putlchar(' ');
			flags->size -= 1;
		}
	}
	else
	{
		while (flags->size > 1)
		{
			count += ft_putlchar(' ');
			flags->size -= 1;
		}
		count += ft_putlchar(c);
	}
	return (count);
}