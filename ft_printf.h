#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(char c, va_list args);
int	ft_puthex(unsigned long n, char *base);
int	ft_putchar(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, char format);

#endif