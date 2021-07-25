/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 06:07:31 by ysong             #+#    #+#             */
/*   Updated: 2021/07/25 22:56:44 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		neg;

	neg = 1;
	if (n > 0)
		neg = -1;
	len = ft_len(n);
	result = ((char *)malloc(sizeof(char) * len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	len--;
	while (len >= 0)
	{
		result[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (neg == -1)
		result[0] = '-';
	return (result);
}
