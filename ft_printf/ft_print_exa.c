/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:29 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 16:19:43 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_exa(t_flags *flags, size_t n, int u)
{
	char *num;
	int count;
	int len;

	if (!n)
		return (ft_print_zero(flags));
	count = 0;
	if(!(num = ft_itoa_base_unsigned(n, 16)))
		return (-1);
	if(u)
		num = ft_toupperstr(num);
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