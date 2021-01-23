/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:58 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/23 10:25:08 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_atoi_abs(const char *nptr)
{
	long int sum;

	sum = 0;
	while (ft_isdigit(*nptr))
	{
		sum *= 10;
		sum += *nptr++ - '0';
		if (sum < 0)
			return (-1);
	}
	return (sum);
}