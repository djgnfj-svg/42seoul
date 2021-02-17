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

//normal 방향 조정?
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

t_vec	ft_cross_product(t_vec u, t_vec v)
{
	t_vec w;

	w.x = u.y * v.z - u.z * v.y;
	//참고 -1곱하는데 나는 그냥으로 진행해보자
	w.y = u.x * v.z - u.z * v.x;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

void			ft_normalize_vector(t_vec *v)
{
	double mod;

	mod = ft_mod_vector(*v);
	v->x = v->x / mod;
	v->y = v->y / mod;
	v->z = v->z / mod;
}

double			ft_mod_vector(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
t_vec		ft_mtx_vct_prod(t_matrix m, t_vec v)
{
	t_vec p;

	p.x = v.x * m.vx.x + v.y * m.vy.x + v.z * m.vz.x;
	p.y = v.x * m.vx.y + v.y * m.vy.y + v.z * m.vz.y;
	p.z = v.x * m.vx.z + v.y * m.vy.z + v.z * m.vz.z;
	return (p);
}