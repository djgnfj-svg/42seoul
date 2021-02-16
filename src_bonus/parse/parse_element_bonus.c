/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:49:30 by ysong             #+#    #+#             */
/*   Updated: 2021/02/17 02:44:36 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec		ft_get_parallel_dir(char *option)
{
	char		**buffer;
	int			i;
	t_vec	dir;

	i = 0;
	buffer = ft_split(option, ':');
	while (buffer[i])
		i++;
	if (i != 2)
		ft_error_handler(BAD_BONUS);
	dir = ft_load_coords(buffer[1]);
	ft_normalize_vector(&dir);
	ft_del_matrix(buffer);
	return (dir);
}

t_vec		ft_is_parallel_light(char *option)
{
	t_vec	dir;

	dir = (t_vec){0, 0, 0};
	if (option)
	{
		if (!ft_strncmp(option, "parallel:", 9))
			dir = ft_get_parallel_dir(option);
		else
			ft_error_handler(BAD_BONUS);
	}
	return (dir);
}
