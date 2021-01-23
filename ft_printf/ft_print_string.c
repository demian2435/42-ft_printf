/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:23:54 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 10:25:22 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_string(t_flags *flags, char *str)
{
	int count;
	int size;

	if (!str)
		return (ft_print_string_NULL(flags));
	size = ft_strlen(str);
	if (flags->point == -1)
		flags->point = size;
	count = 0;
	if (flags->minus)
	{
		if (flags->point >= size)
			count += ft_putlstr(str, size);
		else
			count += ft_putlstr(str, flags->point);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - ft_min(size, flags->point))
			count += ft_putlchar(' ');
		if (flags->point >= size)
			count += ft_putlstr(str, size);
		else
			count += ft_putlstr(str, flags->point);
	}
	return (count);
}