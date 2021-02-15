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

	if (s.cylinder[i]->m && s.cylinder[i]->m > s.cylinder[i]->height)
		auxplane.point = ft_add_vec(s.cylinder[i]->point,
				ft_k_mul_vec(s.cylinder[i]->height, s.cylinder[i]->n));
	else
		auxplane.point = s.cylinder[i]->point;
	auxplane.n = s.cylinder[i]->n;
	if (ft_intersect_caps(&s, r, i, &auxplane))
		if (ft_between_light_source(s.light[s.i_light]->pos
					, auxplane.p, r->origin))
			return (1);
	return (0);
}

int	ft_shadow_cylinder(t_rt rt, t_ray *r, int i)
{
	s.cylinder[i]->m = 0;
	if (ft_intersect_cylinder(&s, r, i))
	{
		s.cylinder[i]->p = ft_add_vec(r->origin,
				ft_k_mul_vec(r->t, r->global));
		if (ft_between_light_source(s.light[s.i_light]->pos
					, s.cylinder[i]->p, r->origin))
		{
			s.cylinder[i]->m = ft_dot_product(s.cylinder[i]->n,
					ft_sub_vec(s.cylinder[i]->p, s.cylinder[i]->point));
			if (s.cylinder[i]->m < s.cylinder[i]->height
					&& s.cylinder[i]->m > 0)
				return (1);
		}
	}
	if (ft_shadow_caps(s, r, i))
		return (1);
	return (0);
}
