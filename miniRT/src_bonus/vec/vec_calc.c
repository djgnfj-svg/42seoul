/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 06:04:22 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:13:29 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ft_k_mul_vec(double k, t_vec v)
{
	t_vec	w;

	w.x = k * v.x;
	w.y = k * v.y;
	w.z = k * v.z;
	return (w);
}

t_vec	ft_sub_vec(t_vec u, t_vec v)
{
	t_vec w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vec	ft_add_vec(t_vec u, t_vec v)
{
	t_vec w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

double	ft_dot_product(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec	ft_cross_product(t_vec u, t_vec v)
{
	t_vec w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = -1.0 * (u.x * v.z - u.z * v.x);
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}
