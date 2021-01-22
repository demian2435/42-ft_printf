#include "ft_printf.h"

int ft_print_exa(t_flags *flags, int n, int u)
{
	ft_initflags(*flags);
	return (n * u);
}