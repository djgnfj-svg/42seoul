/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 04:21:02 by ysong             #+#    #+#             */
/*   Updated: 2021/02/12 22:54:23 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		ft_dot_product(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double			ft_abs(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

t_vec		ft_set_axis(char axis)
{
	t_vec v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	if (axis == 'x')
		v.x = 1;
	else if (axis == 'y')
		v.y = 1;
	else if (axis == 'z')
		v.z = 1;
	return (v);
}