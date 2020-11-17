/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djgnfj <djgnfj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 05:29:23 by ysong             #+#    #+#             */
/*   Updated: 2020/11/16 10:01:59 by djgnfj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void temp_nbr(int n, int fd)
{
	if (n >= 10)
		temp_nbr(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void ft_putnbr_fd(int nb, int fd)
{
	if (fd < 0)
		return;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * 1;
	}
	temp_nbr(nb, fd);
}
