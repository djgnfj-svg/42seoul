/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:16:13 by ysong             #+#    #+#             */
/*   Updated: 2021/07/25 19:14:33 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	unsigned char		*temp_src;

	if (!dest && !src)
		return (0);
	if (dest < src)
	{
		temp_dest = (unsigned char *)dest;
		temp_src = (unsigned char *)src;
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		temp_dest = (unsigned char *)dest + (n - 1);
		temp_src = (unsigned char *)src + (n - 1);
		while (n--)
			*temp_dest-- = *temp_src--;
	}
	return (dest);
}
