/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:23:54 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/25 12:19:18 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_string_2(t_flags *flags, char *str, int len)
{
	int count;

	count = 0;
	while (count < flags->size - ft_min(len, flags->point))
		count += ft_putlchar(' ');
	if (flags->point >= len)
		count += ft_putlstr(str, len);
	else
		count += ft_putlstr(str, flags->point);
	return (count);
}

static int		ft_print_string_1(t_flags *flags, char *str, int len)
{
	int count;

	count = 0;
	if (flags->point >= len)
		count += ft_putlstr(str, len);
	else
		count += ft_putlstr(str, flags->point);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_string(t_flags *flags, char *str)
{
	int count;
	int len;

	if (!str)
		return (ft_print_string_null(flags));
	len = ft_strlen(str);
	if (flags->point <= -1)
		flags->point = len;
	if (flags->zero && flags->size == 0)
	{
		flags->size = flags->point;
		flags->point = -1;
	}
	count = 0;
	if (flags->minus)
		count = ft_print_string_1(flags, str, len);
	else
		count = ft_print_string_2(flags, str, len);
	return (count);
}
