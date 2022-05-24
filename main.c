#include <stdio.h>
#include <limits.h>
#include "ft_printf.c"

int	main(void)
{
	printf(" %i\n", printf("[ %-2d]", -1));
	fflush(stdout);
	printf(" %i\n", ft_printf("[ %-2d]", -1));
	fflush(stdout);
}
