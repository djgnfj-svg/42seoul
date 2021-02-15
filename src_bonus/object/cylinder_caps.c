/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caprt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:02:36 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 07:29:42 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_intersect_caps(t_rt *rt, t_ray *r, int i, t_auxplane *auxplane)
{
	if (ft_intersect_plane(rt, auxplane, r))
		if (ft_get_point_plane(rt, auxplane, r))
			if (ft_mod_vector(ft_sub_vec(auxplane->p, auxplane->point))
					< rt->cylinder[i]->radius)
			{
				if (auxplane->den > 0)
					auxplane->n = ft_k_mul_vec(-1, auxplane->n);
				return (1);
			}
	return (0);
}

t_vec	ft_nearest_cap(t_rt rt, int i)
{
	t_vec	vect[2];
	t_vec	top_side;
	double		dist[2];

	top_side = ft_add_vec(rt.cylinder[i]->point,
			ft_k_mul_vec(rt.cylinder[i]->height, rt.cylinder[i]->n));
	vect[0] = ft_sub_vec(rt.camera[rt.i_cam]->pos, rt.cylinder[i]->point);
	vect[1] = ft_sub_vec(rt.camera[rt.i_cam]->pos, top_side);
	dist[0] = ft_mod_vector(vect[0]);
	dist[1] = ft_mod_vector(vect[1]);
	if (dist[0] > dist[1])
		return (top_side);
	return (rt.cylinder[i]->point);
}

int			ft_draw_caps(t_rt rt, t_ray *r, int i)
{
	double		last_t;
	t_obj_color	obj;
	t_auxplane	auxplane;

	last_t = r->t;
	if (rt.cylinder[i]->m && rt.cylinder[i]->m > rt.cylinder[i]->height)
		auxplane.point = ft_add_vec(rt.cylinder[i]->point,
				ft_k_mul_vec(rt.cylinder[i]->height, rt.cylinder[i]->n));
	else
		auxplane.point = ft_nearest_cap(rt, i);
	auxplane.n = rt.cylinder[i]->n;
	if (ft_intersect_caps(&rt, r, i, &auxplane))
	{
		obj.p = auxplane.p;
		obj.normal = auxplane.n;
		obj.rgb = rt.cylinder[i]->rgb;
		r->color = ft_get_color(rt, obj);
		return (1);
	}
	r->t = last_t;
	return (0);
}
