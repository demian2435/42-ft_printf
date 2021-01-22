#include "ft_printf.h"

t_flags ft_initflags(t_flags flags)
{
	flags.minus = 0;
	flags.point = -1;
	flags.size = 0;
	flags.terminator = 0;
	flags.zero = 0;

	return (flags);
}