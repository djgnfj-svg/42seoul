/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_shadows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:50:21 by ysong             #+#    #+#             */
/*   Updated: 2021/02/15 07:34:53 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

int		ft_shadow_triangle(t_rt rt, t_ray *r, int i)
{
	t_auxplane	auxplane;

	auxplane.point = s.triangle[i]->a;
	auxplane.n = ft_cross_product(s.triangle[i]->e1, s.triangle[i]->e0);
	if (ft_intersect_triangle(&s, r, i, &auxplane))
		if (ft_between_light_source(s.light[s.i_light]->pos
					, auxplane.p, r->origin))
			return (1);
	return (0);
}
