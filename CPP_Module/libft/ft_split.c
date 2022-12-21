/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 05:51:22 by ysong             #+#    #+#             */
/*   Updated: 2021/07/25 19:14:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**split_free(char const **dest, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dest[j]);
	}
	free(dest);
	return (0);
}

static int	numstring(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static char	**my_split(char const *s, char **result, char c, int l)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	j = 0;
	while (s[i] && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		result[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (!result[j])
			return (split_free((char const **)result, j));
		while (s[i] && s[i] != c)
			result[j][k++] = s[i++];
		result[j][k] = '\0';
		j++;
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		l;

	l = numstring(s, c);
	result = (char **)malloc(sizeof(char *) * (l + 1));
	if (!result)
		return (0);
	result = my_split(s, result, c, l);
	return (result);
}
