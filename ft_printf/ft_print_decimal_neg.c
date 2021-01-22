#include "ft_printf.h"

int ft_print_decimal_neg(t_flags *flags, char *num)
{
	int len;
	int count;

	count = 0;
	len = ft_strlen(num) - 1;
	if (flags->minus)
	{
		count += ft_putlchar('-');
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(&num[1], len);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - (ft_max(len, flags->point) + 1))
			count += ft_putlchar(' ');
		count += ft_putlchar('-');
		while (flags->point > len + flags->zero)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(&num[1], len);
	}
	free(num);
	return (count);
}
