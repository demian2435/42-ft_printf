#include "ft_printf.h"

int ft_core_zero(char *str, t_flags *flags, va_list *args)
{
	//printf("\nCORE ZERO\n");
	str++;
	flags->zero = 1;
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

	if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	else if (*str == '.')
	{
		flags->size = flags->point;
		flags->point = -1;
		flags->zero = 0;
		return (ft_core_point(str, flags, args));
	}
	return (-1);
}