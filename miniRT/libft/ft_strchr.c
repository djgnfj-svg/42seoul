/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 06:35:10 by ysong             #+#    #+#             */
/*   Updated: 2020/10/07 12:01:42 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == find)
		return ((char *)(s + i));
	return (0);
}
