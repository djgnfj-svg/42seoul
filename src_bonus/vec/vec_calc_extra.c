/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 06:53:14 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 21:46:23 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix		ft_inv_matrix(t_matrix m)
{
	double		det;
	t_matrix	inv;

	det = ft_det(m);
	inv.vx.x = (m.vy.y * m.vz.z - m.vy.z * m.vz.y) / det;
	inv.vx.y = -1 * (m.vx.y * m.vz.z - m.vx.z * m.vz.y) / det;
	inv.vx.z = (m.vx.y * m.vy.z - m.vx.z * m.vy.y) / det;
	inv.vy.x = -1 * (m.vy.x * m.vz.z - m.vy.z * m.vz.x) / det;
	inv.vy.y = (m.vx.x * m.vz.z - m.vx.z * m.vz.x) / det;
	inv.vy.z = -1 * (m.vx.x * m.vy.z - m.vx.z * m.vy.x) / det;
	inv.vz.x = (m.vy.x * m.vz.y - m.vy.y * m.vz.x) / det;
	inv.vz.y = -1 * (m.vx.x * m.vz.y - m.vx.y * m.vz.x) / det;
	inv.vz.z = (m.vx.x * m.vy.y - m.vx.y * m.vy.x) / det;
	return (inv);
}

int				ft_minus_vector(t_vec *v)
{
	v->x = -1 * v->x;
	v->y = -1 * v->y;
	v->z = -1 * v->z;
	return (1);
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

t_vec		ft_set_hor_axis(t_vec n)
{
	t_vec x;

	x.z = 0;
	if (!n.x && !n.y)
	{
		x.y = 0;
		if (n.z > 0)
			x.x = -1.0;
		else if (n.z < 0)
			x.x = 1.0;
		else if (!n.z)
			ft_error_handler(BAD_FORMAT);
	}
	else
	{
		x.x = n.y;
		x.y = -1.0 * n.x;
	}
	return (x);
}

int				ft_isvoid(t_vec vector)
{
	if (!vector.x && !vector.y && !vector.z)
		return (0);
	return (1);
}