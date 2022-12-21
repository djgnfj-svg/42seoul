/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:07:15 by ysong             #+#    #+#             */
/*   Updated: 2020/10/07 15:15:32 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	temp_dest = dest;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*temp_dest++ = *temp_src++;
	return (dest);
}
