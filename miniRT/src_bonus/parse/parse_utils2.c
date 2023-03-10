/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:28:00 by ysong             #+#    #+#             */
/*   Updated: 2021/03/27 15:32:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_bonus_option(void)
{
	int	bonus;

	bonus = 2;
	return (bonus);
}

int		ft_check_normalized(t_vec *nor)
{
	if (nor->x < -1 || nor->x > 1)
		return (0);
	if (nor->y < -1 || nor->y > 1)
		return (0);
	if (nor->z < -1 || nor->z > 1)
		return (0);
	return (1);
}

void	ft_get_triangle_boundaries(t_triangle *triangle)
{
	triangle->e0 = ft_sub_vec(triangle->b, triangle->a);
	triangle->e1 = ft_sub_vec(triangle->c, triangle->a);
	triangle->det = triangle->e0.x * triangle->e1.y
		- triangle->e0.y * triangle->e1.x;
	triangle->equation = 0;
	if (!triangle->det)
	{
		triangle->det = triangle->e0.y * triangle->e1.z
			- triangle->e1.y * triangle->e0.z;
		triangle->equation = 1;
	}
	if (!triangle->det)
	{
		triangle->det = triangle->e0.x * triangle->e1.z
			- triangle->e0.z * triangle->e1.x;
		triangle->equation = 2;
	}
}
