/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:01:42 by ysong             #+#    #+#             */
/*   Updated: 2021/02/24 14:20:49 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_calc_surface_cylinder(t_rt *rt, t_ray *r, int i)
{
	double	aux;

	if (ft_isvoid(r->origin))
		rt->cylinder[i]->oc = ft_sub_vec(r->origin,
				rt->cylinder[i]->point);
	else
		rt->cylinder[i]->oc = ft_sub_vec(rt->camera[rt->i_cam]->pos,
				rt->cylinder[i]->point);
	aux = ft_dot_product(r->global, rt->cylinder[i]->n);
	rt->cylinder[i]->a = 1 - aux * aux;
	aux = ft_dot_product(rt->cylinder[i]->oc, rt->cylinder[i]->n);
	rt->cylinder[i]->b = 2 * (ft_dot_product(r->global, rt->cylinder[i]->oc)
			- ft_dot_product(r->global, rt->cylinder[i]->n)
			* ft_dot_product(rt->cylinder[i]->oc, rt->cylinder[i]->n));
	rt->cylinder[i]->c = ft_dot_product(rt->cylinder[i]->oc, \
					rt->cylinder[i]->oc)
		- aux * aux - rt->cylinder[i]->radius * rt->cylinder[i]->radius;
	rt->cylinder[i]->discr = rt->cylinder[i]->b * rt->cylinder[i]->b - 4
		* rt->cylinder[i]->a * rt->cylinder[i]->c;
}

int		ft_intersect_cylinder(t_rt *rt, t_ray *r, int i)
{
	double	t;

	t = 0;
	ft_calc_surface_cylinder(rt, r, i);
	if (rt->cylinder[i]->discr < 0)
		return (0);
	rt->cylinder[i]->x1 = (-rt->cylinder[i]->b
			+ sqrt(rt->cylinder[i]->discr)) / (2 * rt->cylinder[i]->a);
	rt->cylinder[i]->x2 = (-rt->cylinder[i]->b
			- sqrt(rt->cylinder[i]->discr)) / (2 * rt->cylinder[i]->a);
	if (rt->cylinder[i]->x1 > rt->cylinder[i]->x2)
		t = rt->cylinder[i]->x2;
	if (t < 0)
		return (0);
	if (t > r->t && !ft_isvoid(r->origin))
		return (0);
	r->t = t;
	return (1);
}

void	ft_color_cylinder(t_rt rt, t_ray *r, int i)
{
	t_obj_color	obj;

	obj.p = rt.cylinder[i]->p;
	obj.normal = rt.cylinder[i]->nsurface;
	obj.rgb = rt.cylinder[i]->rgb;
	obj.bonus = rt.cylinder[i]->bonus;
	r->color = ft_get_color(rt, obj);
}

int		ft_draw_cylinder(t_rt rt, t_ray *r, int i)
{
	double	last_t;

	last_t = r->t;
	if (ft_intersect_cylinder(&rt, r, i))
	{
		rt.cylinder[i]->p = ft_add_vec(rt.camera[rt.i_cam]->pos,
				ft_k_mul_vec(r->t, r->global));
		rt.cylinder[i]->m = ft_dot_product(rt.cylinder[i]->n,
				ft_sub_vec(rt.cylinder[i]->p, rt.cylinder[i]->point));
		rt.cylinder[i]->center = ft_add_vec(rt.cylinder[i]->point,
				ft_k_mul_vec(rt.cylinder[i]->m, rt.cylinder[i]->n));
		rt.cylinder[i]->nsurface = ft_sub_vec(rt.cylinder[i]->p
								, rt.cylinder[i]->center);
		if (rt.cylinder[i]->m < rt.cylinder[i]->height && rt.cylinder[i]->m > 0)
		{
			ft_color_cylinder(rt, r, i);
			return (1);
		}
		r->t = last_t;
	}
	return (ft_draw_caps(rt, r, i));
}
