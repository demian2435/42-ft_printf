#include "ft_printf.h"

char *ft_itoa_base(int number, int base)
{
	char *arr;
	long int temp;
	int count;
	char *str;

	if (number == 0)
	{
		if (!(str = malloc(2 * sizeof(char))))
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	arr = "0123456789abcdef";
	count = 0;
	temp = (long int)number;
	if (number < 0)
	{
		temp = temp * -1;
		count++;
	}
	while (temp > 0)
	{
		temp /= base;
		count++;
	}
	temp = (long int)number;
	if (number < 0)
	{
		temp = temp * -1;
	}
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
	if (number < 0)
		str[count] = '-';
	return (str);
}