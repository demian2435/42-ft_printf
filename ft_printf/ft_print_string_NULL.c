/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_NULL.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:26 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 10:25:21 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_string_NULL(t_flags *flags)
{
	int count;
	int size;
	char *str;

	if (flags->point < -1)
		flags->point = -1;
	str = "(null)";
	size = ft_strlen(str);
	if (flags->point == -1)
		flags->point = size;
	count = 0;
	if (flags->minus)
	{
		if (flags->point >= size)
			count += ft_putlstr(str, size);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else if (flags->point >= size)
	{
		while (count < flags->size - size)
			count += ft_putlchar(' ');
		count += ft_putlstr(str, size);
	}
	else
	{
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	return (count);
}