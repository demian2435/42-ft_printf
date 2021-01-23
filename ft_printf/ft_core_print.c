/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:51 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 10:25:12 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_core_print(char *str, t_flags *flags, va_list *args)
{
	//printf("\nCORE PRINT\n");
	if (*str == 'c')
		return (ft_print_char(flags, va_arg(*args, int)));
	else if (*str == 's')
		return (ft_print_string(flags, va_arg(*args, char *)));
	else if (*str == 'p')
		return (ft_print_pointer(flags, va_arg(*args, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_print_decimal(flags, va_arg(*args, int)));
	else if (*str == 'u')
		return (ft_print_decimal(flags, va_arg(*args, int)));
	else if (*str == 'x')
		return (ft_print_exa(flags, va_arg(*args, int), 0));
	else if (*str == 'X')
		return (ft_print_exa(flags, va_arg(*args, int), 1));
	else if (*str == '%')
		return (ft_putlchar('%'));
	return (-1);
}