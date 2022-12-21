/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:40 by ysong             #+#    #+#             */
/*   Updated: 2020/11/18 13:03:29 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_prec_str(unsigned long long num, t_info *info, char *buf)
{
	int	width;
	int	len;
	int	i;

	len = ft_numlen(num, info);
	width = (info->prec < len) ? len : info->prec;
	if (!(buf = (char *)malloc(sizeof(char) * width + 1)))
		return (0);
	i = 0;
	while (len + i < width)
		buf[i++] = '0';
	buf[width] = '\0';
	i = 1;
	if (num == 0 && info->prec != 0)
		buf[width - i] = '0';
	while (num)
	{
		buf[width - i] = ft_baseset(info->type)[num % info->num_base];
		num /= info->num_base;
		i++;
	}
	if ((info->type == 'd' || info->type == 'i') &&
		info->zero == 0 && info->num_sign == -1)
		buf = ft_strjoin("-", buf, 2);
	return (buf);
}

int		ft_put_minus(int buf_len, t_info *info, char **buf)
{
	int	add;

	add = 0;
	if (info->num_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			add = 1;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (add);
}

int		ft_print_num(unsigned long long num, t_info *info)
{
	char	*buf;
	int		result;

	buf = 0;
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->num_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)num < 0)
	{
		info->num_sign = -1;
		num *= -1;
	}
	buf = put_prec_str(num, info, buf);
	buf = (info->type == 'p') ? ft_strjoin("0x", buf, 2) : buf;
	buf = ft_put_width_str(buf, info);
	ft_put_minus(ft_numlen(num, info), info, &buf);
	result = ft_putstr(buf);
	free(buf);
	return (result);
}
