#include "ft_printf.h"

int	ft_print_int(int n)
{
	long	num;
	int		len;

	len = 0;
	num = n;
	if (num < 0)
	{
		len += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		len += ft_print_int(num / 10);
	len += ft_putchar((num % 10) + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}