/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigungor <bigungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 22:26:40 by bigungor          #+#    #+#             */
/*   Updated: 2026/03/17 02:26:31 by bigungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

static int	control(const char *format, int *i, va_list args)
{
	int	len;

	len = ft_format(format[*i + 1], args);
	if (len == -1)
		return (-1);
	(*i)++;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		tmp;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			tmp = handle_format(format, &i, args);
		else
			tmp = write(1, &format[i], 1);
		if (tmp == -1)
			return (-1);
		len += tmp;
		i++;
	}
	va_end(args);
	return (len);
}
