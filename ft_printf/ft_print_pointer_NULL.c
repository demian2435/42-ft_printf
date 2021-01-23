#include "ft_printf.h"

int ft_print_pointer_NULL(t_flags *flags)
{
	int count;
	int len;

	count = 0;
	len = 3;
	if (flags->minus)
	{
		count += ft_putlstr("0x", 2);
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlchar('0');
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - ft_max(flags->point, len))
			count += ft_putlchar(' ');
		count += ft_putlstr("0x", 2);
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlchar('0');
	}
	return (count);
}