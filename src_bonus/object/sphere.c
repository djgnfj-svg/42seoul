/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:23:01 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:46:35 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_intersect_sphere(t_rt *rt, t_ray *r, int i)
{
	double	oc_mod;

	if (ft_isvoid(r->origin))
		rt->sphere[i]->oc = ft_sub_vec(rt->sphere[i]->center, r->origin);
	else
		rt->sphere[i]->oc = ft_sub_vec(rt->sphere[i]->center
							, rt->camera[rt->i_cam]->pos);
	rt->sphere[i]->p_oc = ft_dot_product(rt->sphere[i]->oc, r->global);
	if (rt->sphere[i]->p_oc < 0)
		return (0);
	oc_mod = ft_mod_vector(rt->sphere[i]->oc);
	rt->sphere[i]->d = sqrt(oc_mod * oc_mod - rt->sphere[i]->p_oc
						* rt->sphere[i]->p_oc);
	if (rt->sphere[i]->d > rt->sphere[i]->radius)
		return (0);
	return (1);
}

int		ft_draw_sphere(t_rt rt, t_ray *r, int i)
{
	double		t;
	t_obj_color	obj;
	
	if (!ft_intersect_sphere(&rt, r, i))
		return (0);
	t = rt.sphere[i]->p_oc - sqrt(rt.sphere[i]->radius * rt.sphere[i]->radius
			- rt.sphere[i]->d * rt.sphere[i]->d);
	if (t > r->t)
		return (0);
	r->t = t;
	obj.p = ft_add_vec(rt.camera[rt.i_cam]->pos
			, ft_k_mul_vec(r->t, r->global));
	obj.normal = ft_sub_vec(obj.p, rt.sphere[i]->center);
	obj.rgb = rt.sphere[i]->rgb;
	obj.center = rt.sphere[i]->center;
	obj.bonus = rt.sphere[i]->bonus;
	r->color = ft_get_color(rt, obj);
	return (1);
}

