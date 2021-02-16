/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_shadows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:50:21 by ysong             #+#    #+#             */
/*   Updated: 2021/02/17 06:29:18 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

int		ft_shadow_triangle(t_rt rt, t_ray *r, int i)
{
	t_auxplane	auxplane;

	auxplane.point = rt.triangle[i]->a;
	auxplane.n = ft_cross_product(rt.triangle[i]->e1, rt.triangle[i]->e0);
	if (ft_intersect_triangle(&rt, r, i, &auxplane))
		if (ft_between_light_source(rt.light[rt.i_light]->pos
					, auxplane.p, r->origin))
			return (1);
	return (0);
}
