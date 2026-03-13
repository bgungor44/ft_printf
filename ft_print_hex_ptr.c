/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigungor <bigungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:27:05 by bigungor          #+#    #+#             */
/*   Updated: 2026/03/13 22:27:07 by bigungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_puthex(n, "0123456789abcdef"));
	return (ft_puthex(n, "0123456789ABCDEF"));
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
