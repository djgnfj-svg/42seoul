/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 23:01:42 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_calc_surface_cylinder(t_rt *rt, t_ray *r, int i)
{
	double	aux;

	if (ft_isvoid(r->origin))
		s->cylinder[i]->oc = ft_sub_vec(r->origin,
				s->cylinder[i]->point);
	else
		s->cylinder[i]->oc = ft_sub_vec(s->camera[s->i_cam]->pos,
				s->cylinder[i]->point);
	aux = ft_dot_product(r->global, s->cylinder[i]->n);
	s->cylinder[i]->a = 1 - aux * aux;
	aux = ft_dot_product(s->cylinder[i]->oc, s->cylinder[i]->n);
	s->cylinder[i]->b = 2 * (ft_dot_product(r->global, s->cylinder[i]->oc)
			- ft_dot_product(r->global, s->cylinder[i]->n)
			* ft_dot_product(s->cylinder[i]->oc, s->cylinder[i]->n));
	s->cylinder[i]->c = ft_dot_product(s->cylinder[i]->oc, s->cylinder[i]->oc)
		- aux * aux - s->cylinder[i]->radius * s->cylinder[i]->radius;
	s->cylinder[i]->discr = s->cylinder[i]->b * s->cylinder[i]->b - 4
		* s->cylinder[i]->a * s->cylinder[i]->c;
}

int		ft_intersect_cylinder(t_rt *rt, t_ray *r, int i)
{
	double	t;

	t = 0;
	ft_calc_surface_cylinder(s, r, i);
	if (s->cylinder[i]->discr < 0)
		return (0);
	s->cylinder[i]->x1 = (-s->cylinder[i]->b
			+ sqrt(s->cylinder[i]->discr)) / (2 * s->cylinder[i]->a);
	s->cylinder[i]->x2 = (-s->cylinder[i]->b
			- sqrt(s->cylinder[i]->discr)) / (2 * s->cylinder[i]->a);
	if (s->cylinder[i]->x1 > s->cylinder[i]->x2)
		t = s->cylinder[i]->x2;
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

	obj.p = s.cylinder[i]->p;
	obj.normal = s.cylinder[i]->nsurface;
	obj.rgb = s.cylinder[i]->rgb;
	obj.bonus = s.cylinder[i]->bonus;
	r->color = ft_get_color(s, obj);
}

int		ft_draw_cylinder(t_rt rt, t_ray *r, int i)
{
	double	last_t;

	last_t = r->t;
	if (ft_intersect_cylinder(&s, r, i))
	{
		s.cylinder[i]->p = ft_add_vec(s.camera[s.i_cam]->pos,
				ft_k_mul_vec(r->t, r->global));
		s.cylinder[i]->m = ft_dot_product(s.cylinder[i]->n,
				ft_sub_vec(s.cylinder[i]->p, s.cylinder[i]->point));
		s.cylinder[i]->center = ft_add_vec(s.cylinder[i]->point,
				ft_k_mul_vec(s.cylinder[i]->m, s.cylinder[i]->n));
		s.cylinder[i]->nsurface = ft_sub_vec(s.cylinder[i]->p
								, s.cylinder[i]->center);
		if (s.cylinder[i]->m < s.cylinder[i]->height && s.cylinder[i]->m > 0)
		{
			ft_color_cylinder(s, r, i);
			return (1);
		}
		r->t = last_t;
	}
	return (0);
}
