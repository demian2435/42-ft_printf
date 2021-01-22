#include "ft_printf.h"

int ft_print_decimal(t_flags *flags, int n)
{
	char *num;
	int len;
	int count;

	if (!n)
		return (ft_print_zero(flags));
	count = 0;
	if (!(num = ft_itoa_base(n, 10)))
		return (-1);
	if (n < 0)
		return (ft_print_decimal_neg(flags, num));
	len = ft_strlen(num);
	if (flags->minus)
	{
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(num, len);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - ft_max(flags->point, len))
			count += ft_putlchar(' ');
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(num, len);
	}
	free(num);
	return (count);
}
