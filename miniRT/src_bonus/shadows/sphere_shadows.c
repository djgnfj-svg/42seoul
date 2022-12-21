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
	if (ft_intersect_sphere(&rt, r, i))
	{
		r->t = rt.sphere[i]->p_oc - sqrt(rt.sphere[i]->radius
				* rt.sphere[i]->radius
				- rt.sphere[i]->d * rt.sphere[i]->d);
		rt.sphere[i]->p = ft_add_vec(r->origin,
				ft_k_mul_vec(r->t, r->global));
		if (ft_between_light_source(rt.light[rt.i_light]->pos_shadow
					, rt.sphere[i]->p, r->origin))
			return (1);
	}
	return (0);
}
