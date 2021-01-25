/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:31 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/25 12:19:12 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_decimal_2(t_flags *flags, char *num, int len)
{
	int count;

	count = 0;
	while (count < flags->size - ft_max(flags->point, len))
		count += ft_putlchar(' ');
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlstr(num, len);
	return (count);
}

static int		ft_print_decimal_1(t_flags *flags, char *num, int len)
{
	int count;

	count = 0;
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlstr(num, len);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_decimal(t_flags *flags, int n)
{
	char	*num;
	int		len;
	int		count;

	if (!n)
		return (ft_print_zero(flags));
	count = 0;
	if (!(num = ft_itoa_base(n, 10)))
		return (-1);
	if (n < 0)
		return (ft_print_decimal_neg(flags, num));
	len = ft_strlen(num);
	if (flags->minus)
		count = ft_print_decimal_1(flags, num, len);
	else if (!flags->zero || (flags->zero && flags->point > 0))
		count = ft_print_decimal_2(flags, num, len);
	else if (flags->zero)
	{
		while (count < flags->size - len)
			count += ft_putlchar('0');
		count += ft_putlstr(num, len);
	}
	free(num);
	return (count);
}
