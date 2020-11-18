/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:41 by ysong             #+#    #+#             */
/*   Updated: 2020/11/18 12:05:16 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*soultion_str(char *str, int end, char *buf, t_info *info)
{
	int		i;
	char	*space;

	if (!(buf = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	i = -1;
	while (++i < end)
		buf[i] = str[i];
	buf[i] = '\0';
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

int		ft_print_string(char *str, t_info *info)
{
	int		result;
	int		str_len;
	char	*buf;

	buf = 0;
	result = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > (size_t)ft_strlen(str))
		info->prec = ft_strlen(str);
	str_len = (info->prec < ft_strlen(str)) ? info->prec : ft_strlen(str);
	buf = soultion_str(str, str_len, buf, info);
	result = ft_putstr(buf);
	free(buf);
	return (result);
}
