/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djgnfj <djgnfj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 00:25:52 by ysong             #+#    #+#             */
/*   Updated: 2020/11/17 21:25:24 by djgnfj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *dest, size_t n)
{
	unsigned char *new_dest;
	size_t i;

	new_dest = dest;
	i = 0;
	while (i++ < n)
		*new_dest++ = 0;
}
