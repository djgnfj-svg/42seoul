/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:43 by ysong             #+#    #+#             */
/*   Updated: 2020/11/18 12:13:00 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_type(char c, t_info *info)
{
	int		i;
	char	*type;

	i = 0;
	type = "csdiupxX%";
	while (type[i])
	{
		if (type[i] == c)
		{
			info->type = c;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_info(va_list ap, char *input, t_info *info, int i)
{
	if (input[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (input[i] == '-')
		info->minus = 1;
	else if (input[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(input[i]) || input[i] == '*')
		check_width_prec(ap, input, info, i);
}

int		ft_print_type(va_list ap, t_info *info)
{
	int result;

	result = 0;
	if (info->type == 'c')
		result = ft_print_char(va_arg(ap, int), info);
	else if (info->type == '%')
		result = ft_print_char('%', info);
	else if (info->type == 's')
		result = ft_print_string(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		result = ft_print_num(va_arg(ap, int), info);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		result = ft_print_num(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		result = ft_print_num(va_arg(ap, unsigned long long), info);
	return (result);
}

int		ft_solution(va_list ap, char *input)
{
	int		i;
	int		result;
	t_info	*info;

	i = 0;
	result = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (0);
	while (input[i])
	{
		while (input[i] != '%' && input[i])
			result += ft_putchar(input[i++]);
		if (input[i] == '%')
		{
			ft_init_info(info);
			while (input[++i] != '\0' && !(ft_check_type(input[i], info)))
				ft_check_info(ap, input, info, i);
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			result += ft_print_type(ap, info);
			i++;
		}
	}
	free(info);
	return (result);
}

int		ft_printf(const char *input, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, input);
	result = ft_solution(ap, (char *)input);
	va_end(ap);
	return (result);
}
