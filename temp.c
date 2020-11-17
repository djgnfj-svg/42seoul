#include "ft_printf.h"
#include "libft/libft.h"

#include "ft_printf.c"
#include "ft_print_num.c"
#include "ft_print_char.c"
#include "ft_print_string.c"
#include "utils.c"

#include "libft/ft_strjoin.c"
#include "libft/ft_strlen.c"
#include "libft/ft_putstr_fd.c"
#include "libft/ft_isdigit.c"
#include "libft/ft_putchar_fd.c"
#include <stdio.h>

int main(void)
{
    int a = -4;
    int b = 0;
    char c = 'a';
    int d = 2147483647;
    int e = -2147483648;
    int f = 42;
    int g = 25;
    int h = 4200;
    int i = 8;
    int j = -12;
    int k = 123456789;
    int l = 0;
    int m = -12345678;
    char *n = "abcdefghijklmnop";
    char *o = "-a";
    char *p = "-12";
    char *q = "0";
    char *r = "%%";
    char *s = "-2147483648";
    char *t = "0x12345678";
    char *u = "-0";
    a = 12;
    b = 18;
    ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
    ft_printf("\n");
    printf(" --- Return : %d\n", printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
    return (0);
}
