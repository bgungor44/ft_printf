#include "ft_printf.h"
#include <stdio.h>
int main()
{
    printf("%d\n", printf(0));
    printf("%d\n", ft_printf(0));
}