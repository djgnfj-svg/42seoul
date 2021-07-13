/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 07:15:27 by ysong             #+#    #+#             */
/*   Updated: 2020/10/07 14:19:58 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;
	size_t	big_len;
	size_t	size;

	if (!*little)
		return ((char *)big);
	if (!big && !little)
		return (0);
	lit_len = ft_strlen(little);
	big_len = ft_strlen(big);
	size = big_len > len ? len : big_len;
	while (size-- >= lit_len)
	{
		if (ft_memcmp(big, little, lit_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
