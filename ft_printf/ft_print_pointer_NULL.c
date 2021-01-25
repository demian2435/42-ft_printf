/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_NULL.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:17:06 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/25 12:20:11 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_null(t_flags *flags)
{
	int count;
	int len;

	count = 0;
	len = 5;
	if (flags->minus)
	{
		count += ft_putlstr("(nil)", len);
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - len)
			count += ft_putlchar(' ');
		count += ft_putlstr("(nil)", len);
	}
	return (count);
}
