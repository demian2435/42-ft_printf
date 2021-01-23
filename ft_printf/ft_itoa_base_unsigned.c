/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:40 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 13:56:38 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_itoa_base_unsigned(int number, int base)
{
	char *arr;
	long int temp;
	int count;
	char *str;

	if (number == 0)
	{
		if (!(str = malloc(2 * sizeof(char))))
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	arr = "0123456789abcdef";
	count = 0;
	temp = (long int)number;
	if (number < 0)
	{
		temp = 4294967295 - ((temp + 1) * -1);
	}
	
	while (temp > 0)
	{
		temp /= base;
		count++;
	}
	temp = (long int)number;
	if (number < 0)
	{
		temp = 4294967295 - ((temp + 1) * -1);
	}
	if (!(str = malloc((count + 1) * sizeof(char))))
		return (NULL);
	str[count] = 0;
	while (temp > 0)
	{
		str[count - 1] = arr[temp % base];
		temp /= base;
		count--;
	}
	count--;
	return (str);
}