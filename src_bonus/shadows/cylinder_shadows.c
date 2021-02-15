/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:46:06 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadow_caps(t_rt rt, t_ray *r, int i)
{
	t_auxplane	auxplane;

	if (rt.cylinder[i]->m && rt.cylinder[i]->m > rt.cylinder[i]->height)
		auxplane.point = ft_add_vec(rt.cylinder[i]->point,
				ft_k_mul_vec(rt.cylinder[i]->height, rt.cylinder[i]->n));
	else
		auxplane.point = rt.cylinder[i]->point;
	auxplane.n = rt.cylinder[i]->n;
	if (ft_intersect_caps(&rt, r, i, &auxplane))
		if (ft_between_light_source(rt.light[rt.i_light]->pos
					, auxplane.p, r->origin))
			return (1);
	return (0);
}

int	ft_shadow_cylinder(t_rt rt, t_ray *r, int i)
{
	rt.cylinder[i]->m = 0;
	if (ft_intersect_cylinder(&rt, r, i))
	{
		rt.cylinder[i]->p = ft_add_vec(r->origin,
				ft_k_mul_vec(r->t, r->global));
		if (ft_between_light_source(rt.light[rt.i_light]->pos
					, rt.cylinder[i]->p, r->origin))
		{
			rt.cylinder[i]->m = ft_dot_product(rt.cylinder[i]->n,
					ft_sub_vec(rt.cylinder[i]->p, rt.cylinder[i]->point));
			if (rt.cylinder[i]->m < rt.cylinder[i]->height
					&& rt.cylinder[i]->m > 0)
				return (1);
		}
	}
	if (ft_shadow_caps(rt, r, i))
		return (1);
	return (0);
}
