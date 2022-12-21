/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:50:23 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 13:47:54 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_intersect_inside_square(t_rt rt, t_auxplane *auxplane, int i)
{
	rt.square[i]->dx = ft_set_axis('x');
	rt.square[i]->dy = ft_cross_product(auxplane->n,
			rt.square[i]->dx);
	if (!ft_isvoid(rt.square[i]->dy))
	{
		rt.square[i]->dx = ft_set_axis('y');
		rt.square[i]->dy = ft_cross_product(auxplane->n,
			rt.square[i]->dx);
	}
	ft_normalize_vector(&rt.square[i]->dx);
	ft_normalize_vector(&rt.square[i]->dy);
	if (ft_abs(ft_dot_product(rt.square[i]->dx,
		ft_sub_vec(auxplane->p, rt.square[i]->center)))
			> rt.square[i]->side || ft_abs(ft_dot_product(rt.square[i]->dy,
			ft_sub_vec(auxplane->p, rt.square[i]->center)))
			> rt.square[i]->side)
		return (0);
	return (1);
}

int		ft_draw_square(t_rt rt, t_ray *r, int i)
{
	double			last_t;
	t_auxplane		auxplane;
	t_obj_color		obj;

	last_t = r->t;
	auxplane.point = rt.square[i]->center;
	auxplane.n = rt.square[i]->n;
	if (ft_intersect_plane(&rt, &auxplane, r))
		if (ft_get_point_plane(&rt, &auxplane, r))
			if (ft_intersect_inside_square(rt, &auxplane, i))
			{
				if (auxplane.den > 0)
					auxplane.n = ft_k_mul_vec(-1, auxplane.n);
				obj.p = auxplane.p;
				obj.normal = auxplane.n;
				obj.rgb = rt.square[i]->rgb;
				obj.bonus = rt.square[i]->bonus;
				r->color = ft_get_color(rt, obj);
				return (1);
			}
	r->t = last_t;
	return (0);
}
