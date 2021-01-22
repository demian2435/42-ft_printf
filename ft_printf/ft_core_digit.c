#include "ft_printf.h"

int ft_core_digit(char *str, t_flags *flags, va_list *args)
{
	//printf("\nCORE DIGIT\n");
	flags->size = ft_atoi_abs(str);
	while (ft_isdigit(*str))
		str++;
	if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	else if (*str == '.' && flags->point == -1)
		return (ft_core_point(str, flags, args));
	return (-1);
}