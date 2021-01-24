/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:48 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 10:25:14 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_core_zero(char *str, t_flags *flags, va_list *args)
{
	//printf("\nCORE ZERO\n");
	str++;
	flags->zero = 1;
	if (ft_isdigit(*str) && *str != '0')
	{
		flags->point = ft_atoi_abs(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		
		flags->point = va_arg(*args, int);
		str++;
		if (flags->point < 0)
		{
			flags->minus = 1;
			flags->size = flags->point * -1;
			flags->point = -1;
		}
	}

	if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	else if (*str == '.')
	{
		flags->size = flags->point;
		flags->point = -1;
		return (ft_core_point(str, flags, args));
	}
	else if (*str == '-')
	{
		flags->size = flags->point;
		flags->point = -1;
		return (ft_core_minus(str, flags, args));
	}
	else if (*str == '0')
	{
		return (ft_core_zero(str, flags, args));
	}
	return (-1);
}