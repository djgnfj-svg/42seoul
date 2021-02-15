/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:02:36 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_intersect_caps(t_rt *rt, t_ray *r, int i, t_auxplane *auxplane)
{
	if (ft_intersect_plane(s, auxplane, r))
		if (ft_get_point_plane(s, auxplane, r))
			if (ft_mod_vector(ft_sub_vec(auxplane->p, auxplane->point))
					< s->cylinder[i]->radius)
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

	top_side = ft_add_vec(s.cylinder[i]->point,
			ft_k_mul_vec(s.cylinder[i]->height, s.cylinder[i]->n));
	vect[0] = ft_sub_vec(s.camera[s.i_cam]->pos, s.cylinder[i]->point);
	vect[1] = ft_sub_vec(s.camera[s.i_cam]->pos, top_side);
	dist[0] = ft_mod_vector(vect[0]);
	dist[1] = ft_mod_vector(vect[1]);
	if (dist[0] > dist[1])
		return (top_side);
	return (s.cylinder[i]->point);
}

int			ft_draw_caps(t_rt rt, t_ray *r, int i)
{
	double		last_t;
	t_obj_color	obj;
	t_auxplane	auxplane;

	last_t = r->t;
	if (s.cylinder[i]->m && s.cylinder[i]->m > s.cylinder[i]->height)
		auxplane.point = ft_add_vec(s.cylinder[i]->point,
				ft_k_mul_vec(s.cylinder[i]->height, s.cylinder[i]->n));
	else
		auxplane.point = ft_nearest_cap(s, i);
	auxplane.n = s.cylinder[i]->n;
	if (ft_intersect_caps(&s, r, i, &auxplane))
	{
		obj.p = auxplane.p;
		obj.normal = auxplane.n;
		obj.rgb = s.cylinder[i]->rgb;
		r->color = ft_get_color(s, obj);
		return (1);
	}
	r->t = last_t;
	return (0);
}
