#include "ft_printf.h"

int ft_core_point(char *str, t_flags *flags, va_list *args)
{
	//printf("\nCORE POINT\n");
	str++;
	if (ft_isdigit(*str))
	{
		flags->point = ft_atoi_abs(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		flags->point = va_arg(*args, int);
		str++;
	}
	else
		flags->point = 0;

	if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	return (-1);
}