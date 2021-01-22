#include "ft_printf.h"

int ft_print_pointer(t_flags *flags, void *ptr)
{
	ft_initflags(*flags);
	if (ptr)
		free(ptr);
	return (1);
}