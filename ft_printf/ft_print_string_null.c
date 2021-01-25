/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_null.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:26 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/25 12:19:17 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_string_null_1(t_flags *flags, char *str, int len)
{
	int		count;

	count = 0;
	if (flags->point >= len)
		count += ft_putlstr(str, len);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int			ft_print_string_null(t_flags *flags)
{
	int		count;
	int		len;
	char	*str;

	if (flags->point < -1)
		flags->point = -1;
	str = "(null)";
	len = ft_strlen(str);
	if (flags->point == -1)
		flags->point = len;
	count = 0;
	if (flags->minus)
		count = ft_print_string_null_1(flags, str, len);
	else if (flags->point >= len)
	{
		while (count < flags->size - len)
			count += ft_putlchar(' ');
		count += ft_putlstr(str, len);
	}
	else
	{
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	return (count);
}
