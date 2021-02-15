/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:23:01 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_intersect_sphere(t_rt *rt, t_ray *r, int i)
{
	double	oc_mod;

	if (ft_isvoid(r->origin))
		s->sphere[i]->oc = ft_sub_vec(s->sphere[i]->center, r->origin);
	else
		s->sphere[i]->oc = ft_sub_vec(s->sphere[i]->center
							, s->camera[s->i_cam]->pos);
	s->sphere[i]->p_oc = ft_dot_product(s->sphere[i]->oc, r->global);
	if (s->sphere[i]->p_oc < 0)
		return (0);
	oc_mod = ft_mod_vector(s->sphere[i]->oc);
	s->sphere[i]->d = sqrt(oc_mod * oc_mod - s->sphere[i]->p_oc
						* s->sphere[i]->p_oc);
	if (s->sphere[i]->d > s->sphere[i]->radius)
		return (0);
	return (1);
}

int		ft_draw_sphere(t_rt rt, t_ray *r, int i)
{
	double		t;
	t_obj_color	obj;

	if (!ft_intersect_sphere(&s, r, i))
		return (0);
	t = s.sphere[i]->p_oc - sqrt(s.sphere[i]->radius * s.sphere[i]->radius
			- s.sphere[i]->d * s.sphere[i]->d);
	if (t > r->t)
		return (0);
	r->t = t;
	obj.p = ft_add_vec(s.camera[s.i_cam]->pos
			, ft_k_mul_vec(r->t, r->global));
	obj.normal = ft_sub_vec(obj.p, s.sphere[i]->center);
	obj.rgb = s.sphere[i]->rgb;
	obj.center = s.sphere[i]->center;
	obj.bonus = s.sphere[i]->bonus;
    //여기하느중임
	r->color = ft_get_color(s, obj);
	return (1);
}

