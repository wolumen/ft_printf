#include "ft_printf.h"

int main(void)
{
	ft_printf("%s oder aber auch %%    ", "ein string");
	ft_printf("%p    ", NULL);
	ft_printf("%adfadf    ");
	ft_printf("%s    ", 3);

	return (0);
}