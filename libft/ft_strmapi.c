/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 07:06:42 by ysong             #+#    #+#             */
/*   Updated: 2021/07/25 19:11:12 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp_s;
	size_t	i;

	if (s == 0 || f == 0)
		return (0);
	temp_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!temp_s)
		return (0);
	i = 0;
	while (s[i])
	{
		temp_s[i] = f(i, s[i]);
		i++;
	}
	temp_s[i] = '\0';
	return (temp_s);
}
