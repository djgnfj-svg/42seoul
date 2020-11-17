#include "ft_printf.h"

void ft_init_info(t_info *info)
{
    info->minus = 0;
    info->width = 0;
    info->zero = 0;
    info->prec = -1;
    info->num_base = 10;
    info->num_sign = 1;
}

void ft_check_width_and_prec(va_list ap, char *input, t_info *info, int i)
{
    if (ft_isdigit(input[i]))
    {
        if (info->prec == -1)
            info->width = info->width * 10 + input[i] - 48;
        else
            info->prec = info->prec * 10 + input[i] - 48;
    }
    else if (input[i] == '*')
    {
        if (info->prec == -1)
        {
            info->width = va_arg(ap, int);
            if (info->width < 0)
            {
                info->width *= -1;
                info->minus = 1;
            }
        }
        else
            info->prec = va_arg(ap, int);
    }
}

int ft_numlen(unsigned long long num, t_info *info)
{
    int i;

    if (num == 0 && info->prec != 0)
        return (1);
    i = 0;
    while (num)
    {
        num /= info->num_base;
        i++;
    }
    return (i);
}
char *ft_baseset(char type)
{
    if (type == 'u' || type == 'd' || type == 'i')
        return ("0123456789");
    else if (type == 'x' || type == 'p')
        return ("0123456789abcdef");
    else if (type == 'X')
        return ("0123456789ABCDEF");
    return (0);
}

char *ft_put_width_str(char *buf, t_info *info)
{
    char *space;
    int i;

    if (info->width <= ft_strlen(buf))
        return (buf);
    space = (char *)malloc(sizeof(char) * (info->width - ft_strlen(buf) + 1));
    i = -1;
    while (++i < (info->width - ft_strlen(buf)))
        space[i] = (info->zero) ? '0' : ' ';

    space[i] = '\0';
    if (info->minus)
        buf = ft_strjoin(buf, space, 3);
    else
        buf = ft_strjoin(space, buf, 3);
    return (buf);
}