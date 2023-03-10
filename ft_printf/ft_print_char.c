/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:37 by ysong             #+#    #+#             */
/*   Updated: 2020/11/18 11:32:07 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_width(t_info *info)
{
	int	result;
	int	len;

	len = 1;
	result = 0;
	while (len < info->width)
	{
		result += (info->zero) ? ft_putchar('0') : ft_putchar(' ');
		len++;
	}
	return (result);
}

int	ft_print_char(int c, t_info *info)
{
	int	result;

	result = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus)
	{
		result += ft_putchar(c);
		result += ft_put_width(info);
	}
	else
	{
		result += ft_put_width(info);
		result += ft_putchar(c);
	}
	return (result);
}
