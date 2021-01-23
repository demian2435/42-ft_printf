#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//void *test = malloc(1);
	static int test = 42;
	int res = ft_printf("%p\n", &test);
	int res2 = printf("%p\n", &test);
	printf("\n%d\n%d\n", res, res2);
}