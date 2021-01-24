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

int ft_print_pointer(t_flags *flags, size_t ptr)
{
	char *num;
	int count;
	int len;

	if (!ptr)
		return (ft_print_pointer_NULL(flags));
	if(!(num = ft_itoa_base_unsigned_long(ptr, 16)))
		return (-1);
	count = 0;
	len = ft_strlen(num);
	if (flags->minus)
	{
		count += ft_putlstr("0x", 2);
		count += ft_putlstr(num, len);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - len - 2)
			count += ft_putlchar(' ');
		count += ft_putlstr("0x", 2);
		count += ft_putlstr(num, len);
	}
	free(num);
	return (count);
}