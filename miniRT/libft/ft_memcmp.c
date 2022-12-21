/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:01:23 by ysong             #+#    #+#             */
/*   Updated: 2020/10/07 11:41:00 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*temp_ptr1;
	unsigned char	*temp_ptr2;
	size_t			i;

	temp_ptr1 = (unsigned char *)ptr1;
	temp_ptr2 = (unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (temp_ptr1[i] != temp_ptr2[i])
			return (temp_ptr1[i] - temp_ptr2[i]);
		i++;
	}
	return (0);
}
