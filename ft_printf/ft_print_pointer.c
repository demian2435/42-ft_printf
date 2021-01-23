/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:27 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 17:02:51 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_pointer(t_flags *flags, void *ptr)
{
	char *num;
	char *address;
	int count;
	int len;

	if (!ptr)
		return (ft_print_pointer_NULL(flags));
	if(!(num = ft_itoa_base_unsigned((int)ptr, 16)))
		return (-1);
	if(!(address = ft_itoa_base_unsigned((long int)ptr>>16, 16)))
		return (-1);
	count = 0;
	len = 14;
	if (flags->minus)
	{
		count += ft_putlstr("0x", 2);
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(address, 4);
		count += ft_putlstr(num, 8);
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
		count += ft_putlstr(address, 4);
		count += ft_putlstr(num, 8);
	}
	free(num);
	free(address);
	return (count);
}