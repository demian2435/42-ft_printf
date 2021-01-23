/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:22 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 10:25:23 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_zero(t_flags *flags)
{
	char *num;
	int len;
	int count;

	count = 0;
	num = "0";
	len = 1;
	if (flags->minus)
	{
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		if(flags->point > 0 || flags->point == -1)
			count += ft_putlstr(num, len);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else if (flags->point > 0 || flags->point == -1)
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
	else
	{
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	return (count);
}