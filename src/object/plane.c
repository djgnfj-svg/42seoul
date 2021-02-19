/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:48:43 by ysong             #+#    #+#             */
/*   Updated: 2021/02/18 23:46:28 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_intersect_plane(t_rt *rt, t_auxplane *plane, t_ray *r)
{
	if (ft_isvoid(r->origin))
		plane->po = ft_sub_vec(r->origin, plane->point);
	else
		plane->po = ft_sub_vec(rt->camera[rt->i_cam]->pos, plane->point);
	plane->den = ft_dot_product(plane->n, r->global);
	if (plane->den)
	{
		plane->num = ft_dot_product(plane->n, plane->po);
		if (plane->num * plane->den < 0)
			return (1);
	}
	return (0);
}

int			ft_get_point_plane(t_rt *rt, t_auxplane *plane, t_ray *r)
{
	double	t;

	t = -1 * (plane->num / plane->den);
	if (t > r->t && !ft_isvoid(r->origin))
		return (0);
	r->t = t + FLT_EPSILON;
	if (ft_isvoid(r->origin))
		plane->p = ft_add_vec(r->origin,
				ft_k_mul_vec(r->t, r->global));
	else
		plane->p = ft_add_vec(rt->camera[rt->i_cam]->pos,
				ft_k_mul_vec(r->t, r->global));
	return (1);
}

int					ft_draw_plane(t_rt rt, t_ray *r, int i)
{
	t_auxplane		auxplane;
	t_obj_color		obj;

	auxplane.point = rt.plane[i]->point;
	auxplane.n = rt.plane[i]->n;
	if (ft_intersect_plane(&rt, &auxplane, r))
		if (ft_get_point_plane(&rt, &auxplane, r))
		{
			if (auxplane.den > 0)
				auxplane.n = ft_k_mul_vec(-1, auxplane.n);
			obj.p = auxplane.p;
			obj.center = auxplane.point;
			obj.normal = auxplane.n;
			obj.rgb = rt.plane[i]->rgb;
			obj.bonus = rt.plane[i]->bonus;
			r->color = ft_get_color(rt, obj);
			return (1);
		}
	return (0);
}
