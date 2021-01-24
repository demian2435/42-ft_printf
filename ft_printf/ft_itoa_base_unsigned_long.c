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

static char		*ft_itoa_base_unsigned_long_bis(size_t number, int base)
{
	char	*arr;
	size_t	temp;
	int		count;
	char	*str;

	arr = "0123456789abcdef";
	count = 0;
	temp = number;
	while (temp > 0)
	{
		temp /= base;
		count++;
	}
	temp = number;
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

char		*ft_itoa_base_unsigned_long(size_t number, int base)
{
	char	*str;
	
	if (number == 0)
	{
		if (!(str = malloc(2 * sizeof(char))))
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	return (ft_itoa_base_unsigned_long_bis(number, base));
}