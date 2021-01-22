#include "ft_printf.h"

int ft_core_star(char *str, t_flags *flags, va_list *args)
{
	//printf("\nCORE STAR\n");
	str++;
	flags->size = va_arg(*args, int);
	if (flags->size < 0)
	{
		flags->minus = 1;
		flags->size *= -1;
	}
	if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	else if (*str == '.' && flags->point == -1)
		return (ft_core_point(str, flags, args));
	return (-1);
}