#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		len += write(1, str, 1);
		str++;
	}
	return (len);
}