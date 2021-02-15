/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_shadows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:38:28 by ysong             #+#    #+#             */
/*   Updated: 2021/02/16 01:02:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadow_sphere(t_rt rt, t_ray *r, int i)
{
	if (ft_intersect_sphere(&s, r, i))
	{
		r->t = s.sphere[i]->p_oc - sqrt(s.sphere[i]->radius
				* s.sphere[i]->radius
				- s.sphere[i]->d * s.sphere[i]->d);
		s.sphere[i]->p = ft_add_vec(r->origin,
				ft_k_mul_vec(r->t, r->global));
		if (ft_between_light_source(s.light[s.i_light]->pos_shadow
					, s.sphere[i]->p, r->origin))
			return (1);
	}
	return (0);
}
