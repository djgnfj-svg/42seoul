/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 06:40:11 by ysong             #+#    #+#             */
/*   Updated: 2020/11/18 13:09:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free_target)
{
	char	*result;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < s1_len)
		result[i] = s1[i];
	if (free_target == 1 || free_target == 3)
		free(s1);
	j = 0;
	while (j < s2_len)
		result[i++] = s2[j++];
	if (free_target == 2 || free_target == 3)
		free(s2);
	result[i] = 0;
	return (result);
}
