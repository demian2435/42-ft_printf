#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	t_flags flags;
	int count;
	int res;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			count += ft_putlchar(*str);
			str++;
		}
		else
		{
			str++;
			res = 0;
			flags = ft_initflags(flags);
			if (*str == '0')
				res += ft_core_zero((char *)str, &flags, &args);
			else if (*str == '-')
				res += ft_core_minus((char *)str, &flags, &args);
			else if (*str == '*')
				res += ft_core_star((char *)str, &flags, &args);
			else if (*str == '.')
				res += ft_core_point((char *)str, &flags, &args);
			else if (ft_isdigit(*str))
				res += ft_core_digit((char *)str, &flags, &args);
			else if (ft_isterminator(*str))
				res += ft_core_print((char *)str, &flags, &args);
			else
				return (-1);
			if (res == -1)
				return (-1);
			count += res;
			while (!ft_isterminator(*str))
				str++;
			str++;
		}
	}
	va_end(args);
	return (count);
}